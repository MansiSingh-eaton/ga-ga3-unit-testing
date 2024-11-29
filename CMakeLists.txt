cmake_minimum_required(VERSION 3.17)

project(googletest_sample)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_TAG release-1.11.0)
FetchContent_MakeAvailable(googletest)

# Add source files
add_library(SourceCode STATIC src/SourceA.cpp src/SourceB.cpp)

# Include directories for source and mock headers
include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_SOURCE_DIR}/test/mocks)

# Define the GTest imported target
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Define the GMock imported target
add_library(GMock::GMock INTERFACE IMPORTED)
target_link_libraries(GMock::GMock INTERFACE gmock_main)

# Add test executables and link them to the source code and GTest
add_executable(testRunnerA ${CMAKE_SOURCE_DIR}/test/src/testA.cpp)
target_link_libraries(testRunnerA PRIVATE SourceCode GTest::GTest)

add_executable(testRunnerB ${CMAKE_SOURCE_DIR}/test/src/testB.cpp)
target_link_libraries(testRunnerB PRIVATE SourceCode GTest::GTest)

add_executable(testRunnerMockB ${CMAKE_SOURCE_DIR}/test/src/UsingMockB/testAusingmockB.cpp)
target_link_libraries(testRunnerMockB PRIVATE  substitute_files GTest::GTest GMock::GMock)

# Enable testing
enable_testing()

# Add tests
add_test(NAME testRunnerA COMMAND testRunnerA)
add_test(NAME testRunnerB COMMAND testRunnerB)
add_test(NAME testRunnerMockB COMMAND testRunnerMockB)

# Include CTest
include(CTest)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(SourceCode PRIVATE --coverage) 
    target_link_libraries(SourceCode PRIVATE --coverage)
    target_compile_options(testRunnerA PRIVATE --coverage)
    target_link_libraries(testRunnerA PRIVATE --coverage)
    target_compile_options(testRunnerB PRIVATE --coverage)
    target_link_libraries(testRunnerB PRIVATE --coverage)
	target_compile_options(testRunnerMockB PRIVATE --coverage)
    target_link_libraries(testRunnerMockB PRIVATE --coverage)
	
endif()

# Define the test suite list
set(test_suite_list testRunnerA testRunnerB testRunnerMockB)

# Custom target for test suite
add_custom_target(test_suite
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS testRunnerA testRunnerB testRunnerMockB
)

# Custom target for test suite list
foreach(target IN LISTS test_suite_list)
    add_dependencies(test_suite ${target})
endforeach()

# Custom target for coverage
add_custom_target(coverage
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_CTEST_COMMAND: ${CMAKE_CTEST_COMMAND}"
    COMMAND ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 ${CMAKE_CTEST_COMMAND} --output-junit XML_Report.xml 
    COMMAND ${CMAKE_COMMAND} -E echo "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}"
    # Use the config file in the gcovr call
	COMMAND gcovr -r ${CMAKE_SOURCE_DIR}  --exclude '.*_deps.*' --object-directory ${CMAKE_BINARY_DIR}/CMakeFiles/SourceCode.dir/src . 
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS test_suite
)

# Custom target for coverage report
add_custom_target(coverage_report
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}/coverage
	COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/coverage
	COMMAND gcovr -r ${CMAKE_SOURCE_DIR} --exclude '.*_deps.*' --html-details -o ${CMAKE_BINARY_DIR}/coverage/report.html
	WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS coverage
)

# Custom target for cleaning the project
if(WIN32)
    add_custom_target(Cleanup
        COMMAND rmdir /s /q build
    )
else() 
    add_custom_target(Cleanup
        COMMAND rm -rf build/
    )
endif()

