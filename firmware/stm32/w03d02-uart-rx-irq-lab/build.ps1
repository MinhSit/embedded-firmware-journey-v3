param(
    [switch]$Clean
)

$ErrorActionPreference = 'Stop'

$labRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$buildDir = Join-Path $labRoot 'build'
$pluginRoot = 'C:\ST\STM32CubeIDE_2.0.0\STM32CubeIDE\plugins'
$toolchainMatches = @(
    Get-ChildItem -LiteralPath $pluginRoot -Directory |
        Where-Object { $_.Name -like 'com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.13.3.rel1.win32_*' }
)

if ($toolchainMatches.Count -ne 1) {
    throw "Expected exactly one STM32CubeIDE GNU Tools 13.3.rel1 installation under $pluginRoot; found $($toolchainMatches.Count)."
}

$toolBin = Join-Path $toolchainMatches[0].FullName 'tools\bin'
$gcc = Join-Path $toolBin 'arm-none-eabi-gcc.exe'
$size = Join-Path $toolBin 'arm-none-eabi-size.exe'
$objdump = Join-Path $toolBin 'arm-none-eabi-objdump.exe'

foreach ($tool in @($gcc, $size, $objdump)) {
    if (-not (Test-Path -LiteralPath $tool -PathType Leaf)) {
        throw "Required tool not found: $tool"
    }
}

if ($Clean -and (Test-Path -LiteralPath $buildDir)) {
    $resolvedLab = [System.IO.Path]::GetFullPath($labRoot)
    $resolvedBuild = [System.IO.Path]::GetFullPath($buildDir)
    if (-not $resolvedBuild.StartsWith($resolvedLab + [System.IO.Path]::DirectorySeparatorChar, [System.StringComparison]::OrdinalIgnoreCase)) {
        throw "Refusing to remove build directory outside lab root: $resolvedBuild"
    }
    Remove-Item -LiteralPath $resolvedBuild -Recurse -Force
}

New-Item -ItemType Directory -Path $buildDir -Force | Out-Null

$commonFlags = @(
    '-mcpu=cortex-m4',
    '-mthumb',
    '-mfpu=fpv4-sp-d16',
    '-mfloat-abi=hard',
    '-DSTM32F446xx',
    '-Iinclude',
    '-ffunction-sections',
    '-fdata-sections',
    '-Wall',
    '-Wextra',
    '-Wpedantic',
    '-g3',
    '-O0'
)

Push-Location $labRoot
try {
    & $gcc @commonFlags '-std=gnu11' '-c' 'main.c' '-o' 'build/main.o'
    if ($LASTEXITCODE -ne 0) { throw 'main.c compilation failed.' }

    & $gcc @commonFlags '-std=gnu11' '-c' 'uart_polling.c' '-o' 'build/uart_polling.o'
    if ($LASTEXITCODE -ne 0) { throw 'uart_polling.c compilation failed.' }

    & $gcc @commonFlags '-std=gnu11' '-c' 'system_stm32f4xx.c' '-o' 'build/system_stm32f4xx.o'
    if ($LASTEXITCODE -ne 0) { throw 'system_stm32f4xx.c compilation failed.' }

    & $gcc @commonFlags '-x' 'assembler-with-cpp' '-c' 'startup_stm32f446retx.s' '-o' 'build/startup_stm32f446retx.o'
    if ($LASTEXITCODE -ne 0) { throw 'startup_stm32f446retx.s assembly failed.' }

    $linkFlags = @(
        '-mcpu=cortex-m4',
        '-mthumb',
        '-mfpu=fpv4-sp-d16',
        '-mfloat-abi=hard',
        '-TSTM32F446RETX_FLASH.ld',
        '--specs=nosys.specs',
        '--specs=nano.specs',
        '-Wl,-Map=build/w03d02-uart-rx-irq-lab.map',
        '-Wl,--gc-sections',
        '-static',
        'build/startup_stm32f446retx.o',
        'build/system_stm32f4xx.o',
        'build/main.o',
        'build/uart_polling.o',
        '-Wl,--start-group',
        '-lc',
        '-lm',
        '-Wl,--end-group',
        '-o',
        'build/w03d02-uart-rx-irq-lab.elf'
    )
    & $gcc @linkFlags
    if ($LASTEXITCODE -ne 0) { throw 'Link failed.' }

    & $size 'build/w03d02-uart-rx-irq-lab.elf'
    if ($LASTEXITCODE -ne 0) { throw 'Size inspection failed.' }

    & $objdump '-h' '-S' 'build/w03d02-uart-rx-irq-lab.elf' | Set-Content -LiteralPath 'build/w03d02-uart-rx-irq-lab.list' -Encoding ascii
    if ($LASTEXITCODE -ne 0) { throw 'Objdump inspection failed.' }
}
finally {
    Pop-Location
}
