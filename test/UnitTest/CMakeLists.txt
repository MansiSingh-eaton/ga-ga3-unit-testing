cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 17)
include(GoogleTest)
enable_testing()

if(EXISTS ${CMAKE_BINARY_DIR}/gcovr.cfg)
    file(REMOVE ${CMAKE_BINARY_DIR}/gcovr.cfg)
endif()

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)

add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -Wall -fprofile-arcs -ftest-coverage -fprofile-generate -Wno-unused-function -Wunused-variable -Wunused-but-set-variable")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -fprofile-generate -Wunused-variable -Wunused-but-set-variable -Wno-unused-function -Wno-error=conversion -fcheck-new -std=c++14 -Wno-register -fno-exceptions -fno-rtti --coverage -fexceptions")

set(UNIT_TEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

# Include utility scripts
include(${CMAKE_CURRENT_SOURCE_DIR}/scripts/GlobUtils.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/scripts/TestUtils.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/scripts/SubstitutionUtils.cmake)

set(SOURCE_CODE ${CMAKE_CURRENT_SOURCE_DIR}/../../src)

add_subdirectory(./src)

if(WIN32)
 add_custom_target(clean_project
    COMMAND rmdir /s /q build
)
else() 
 add_custom_target(clean_project
    COMMAND rm -rf build/
    )
endif()

add_custom_target(test_suite)
foreach(target IN LISTS test_suite_list)
    add_dependencies(test_suite ${target})
endforeach()

# Custom target for coverage
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_CTEST_COMMAND: ${CMAKE_CTEST_COMMAND}"
    COMMAND ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND} --output-junit XML_Report.xml 
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}"
    # Use the config file in the gcovr call
    COMMAND gcovr -b -r ${CMAKE_BINARY_DIR} --config ${CMAKE_BINARY_DIR}/gcovr.cfg .
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS test_suite
)

# Custom target for coverage report
add_custom_target(coverage_report
    COMMAND ${CMAKE_COMMAND} -E remove_directory coverage
    COMMAND mkdir coverage
    COMMAND gcovr -r ${CMAKE_BINARY_DIR} --config ${CMAKE_BINARY_DIR}/gcovr.cfg . --html-details coverage/report.html
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS coverage
)
