cmake_minimum_required(VERSION 3.20)

project(w02_startup_simulator LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_library(startup_sim STATIC
    src/app.c
    src/sim_cpu.c
    src/sim_fault.c
    src/sim_memory.c
    src/sim_trace.c
    src/sim_vector.c
    src/startup.c
)

target_include_directories(startup_sim PUBLIC include)

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(startup_sim PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
    )
elseif(MSVC)
    target_compile_options(startup_sim PRIVATE /W4 /WX)
endif()

function(add_startup_lab_executable target source)
    add_executable(${target} ${source})
    target_link_libraries(${target} PRIVATE startup_sim)
    if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        target_compile_options(${target} PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
        )
    elseif(MSVC)
        target_compile_options(${target} PRIVATE /W4 /WX)
    endif()
endfunction()

enable_testing()

add_startup_lab_executable(test_memory tests/test_memory.c)
add_startup_lab_executable(test_reset tests/test_reset.c)
add_startup_lab_executable(test_startup tests/test_startup.c)
add_startup_lab_executable(test_faults tests/test_faults.c)
add_startup_lab_executable(startup_demo demo/startup_demo.c)

add_test(NAME memory_layout COMMAND test_memory)
add_test(NAME cpu_reset COMMAND test_reset)
add_test(NAME learner_startup COMMAND test_startup)
add_test(NAME fault_campaigns COMMAND test_faults)
