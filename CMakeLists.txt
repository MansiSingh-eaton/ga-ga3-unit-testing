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

# Define the GTest imported target
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

# Add test executables and link them to the source code and GTest
add_executable(testRunnerA test/testA.cpp)
target_link_libraries(testRunnerA PRIVATE SourceCode GTest::GTest)

add_executable(testRunnerB test/testB.cpp)
target_link_libraries(testRunnerB PRIVATE SourceCode GTest::GTest)

# Enable testing
enable_testing()

# Add tests
add_test(NAME testRunnerA COMMAND testRunnerA)
add_test(NAME testRunnerB COMMAND testRunnerB)

# Include CTest
include(CTest)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(SourceCode PRIVATE --coverage) 
    target_link_libraries(SourceCode PRIVATE --coverage)
    target_compile_options(testRunnerA PRIVATE --coverage)
    target_link_libraries(testRunnerA PRIVATE --coverage)
    target_compile_options(testRunnerB PRIVATE --coverage)
    target_link_libraries(testRunnerB PRIVATE --coverage)
	
endif()

# Define the test suite list
set(test_suite_list testRunnerA testRunnerB)

# Custom target for test suite
add_custom_target(test_suite
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS testRunnerA testRunnerB
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
    add_custom_target(GoogleTestPseudo
        COMMAND rmdir /s /q build
    )
else() 
    add_custom_target(GoogleTestPseudo
        COMMAND rm -rf build/
    )
endif()

