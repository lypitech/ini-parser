cmake_minimum_required(VERSION 3.16)

project(iniparser
    VERSION 1.0.0
    DESCRIPTION "INI file parser"
    HOMEPAGE_URL "https://github.com/lypitech/ini-parser"
    LANGUAGES CXX
)

# ============================================================
#  Compiler settings
# ============================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

# ============================================================
#  Library target
# ============================================================
add_library(${PROJECT_NAME} STATIC
    src/Parser.cpp
)

# Public headers
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    OUTPUT_NAME ${PROJECT_NAME}
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# ============================================================
#  Tests
# ============================================================
enable_testing()

add_executable(test_iniparser tests/Tests.cpp)

target_link_libraries(test_iniparser PRIVATE iniparser)

target_include_directories(test_iniparser PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_test(NAME ParserTest COMMAND test_iniparser)
