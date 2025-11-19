cmake_minimum_required(VERSION 3.20)

project(iniparser
    VERSION 1.0.0
    DESCRIPTION "INI file parser"
    HOMEPAGE_URL "https://github.com/lypitech/ini-parser"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for clangd

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# ==============================================================================
#  Dependencies
# ==============================================================================
include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

# ==============================================================================
#  Source files
# ==============================================================================
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

# ==============================================================================
#  Include paths
# ==============================================================================
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

# ==============================================================================
#  Compiler flags
# ==============================================================================
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -DDEBUG_MODE")

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall -Wextra
        -Winit-self
        -Wshadow -Wundef
        -Wredundant-decls -Wunreachable-code
        -Wwrite-strings
        -pedantic
        -Wstrict-overflow=2
        --param max-inline-insns-single=200
    )
endif()

# ==============================================================================
#  Custom build targets
# ==============================================================================
add_custom_target(debug
    COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_COMMAND} --build .
    COMMENT "Building in debug mode with DEBUG_MODE defined"
)

add_custom_target(re
    COMMAND ${CMAKE_COMMAND} --build . --target clean
    COMMAND ${CMAKE_COMMAND} --build . --target all
)

# ==============================================================================
#  Installation
# ==============================================================================
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# ==============================================================================
#  Tests
# ==============================================================================
enable_testing()

add_subdirectory(tests)
