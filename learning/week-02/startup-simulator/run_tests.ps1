$ErrorActionPreference = 'Stop'

if (Test-Path variable:PSNativeCommandUseErrorActionPreference) {
    $PSNativeCommandUseErrorActionPreference = $false
}

$labRoot = Split-Path -Parent $MyInvocation.MyCommand.Path
$buildDir = Join-Path $labRoot 'build'

$cmakeCommand = Get-Command cmake -ErrorAction SilentlyContinue
$cmakeCandidates = @(
    'C:\Program Files\CMake\bin\cmake.exe',
    'C:\Program Files\JetBrains\CLion 2025.1.1\bin\cmake\win\x64\bin\cmake.exe',
    'C:\msys64\ucrt64\bin\cmake.exe'
)

if ($null -ne $cmakeCommand) {
    $cmake = $cmakeCommand.Source
} else {
    $cmake = $cmakeCandidates |
        Where-Object { Test-Path -LiteralPath $_ -PathType Leaf } |
        Select-Object -First 1
}

if ([string]::IsNullOrWhiteSpace($cmake)) {
    throw 'CMake was not found on PATH or in the supported local locations.'
}

$ctest = Join-Path (Split-Path -Parent $cmake) 'ctest.exe'
$gccCommand = Get-Command gcc -ErrorAction SilentlyContinue
$makeCommand = Get-Command mingw32-make -ErrorAction SilentlyContinue

if ($null -eq $gccCommand) {
    throw 'Host GCC was not found on PATH.'
}
if ($null -eq $makeCommand) {
    throw 'mingw32-make was not found on PATH.'
}
if (-not (Test-Path -LiteralPath $ctest -PathType Leaf)) {
    throw "CTest was not found beside CMake: $ctest"
}

& $cmake `
    -S $labRoot `
    -B $buildDir `
    -G 'MinGW Makefiles' `
    "-DCMAKE_C_COMPILER=$($gccCommand.Source)" `
    "-DCMAKE_MAKE_PROGRAM=$($makeCommand.Source)"
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& $cmake --build $buildDir
if ($LASTEXITCODE -ne 0) {
    exit $LASTEXITCODE
}

& $ctest --test-dir $buildDir --verbose
exit $LASTEXITCODE
