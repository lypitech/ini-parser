find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

# ==============================================================================
#  Create iniparser_lib library
# ==============================================================================
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    # ...
)
# Avoid multiple main definitions
list(FILTER TEST_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

if(TEST_SOURCES)
    add_library(iniparser_lib ${TEST_SOURCES})
    target_include_directories(iniparser_lib PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    )
endif()

# ==============================================================================
# Collect all test files
# ==============================================================================
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS "*.cpp")

foreach(TEST_FILE ${TEST_FILES})
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    add_executable(${TEST_NAME} ${TEST_FILE})

    target_link_libraries(${TEST_NAME}
        GTest::gtest
        GTest::gtest_main
    )

    if(TARGET iniparser_lib)
        target_link_libraries(${TEST_NAME} iniparser_lib)
    endif()

    gtest_discover_tests(${TEST_NAME})
endforeach()
