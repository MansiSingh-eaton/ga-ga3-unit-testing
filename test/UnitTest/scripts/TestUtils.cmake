cmake_minimum_required(VERSION 3.10)

function(create_test_suite target_name)
    add_executable(${target_name})
    message(STATUS "Creating test suite: ${target_name}")

    target_link_libraries(
        ${target_name} 
        PRIVATE GTest::gtest_main gmock gmock_main
    )

    #gtest_discover_tests(${target_name})
    gtest_discover_tests(${target_name} TEST_PREFIX ${target_name}::)
    add_test(NAME ${target_name} COMMAND ${target_name})

    get_property(TEST_EXECUTABLES GLOBAL PROPERTY TEST_EXECUTABLES)

    list(APPEND TEST_EXECUTABLES ${target_name})

    set_property(GLOBAL PROPERTY TEST_EXECUTABLES "${TEST_EXECUTABLES}")
    set(tmp_test_suite_list ${test_suite_list})
    
    if(NOT "${test_suite_list}" STREQUAL "")
        set(test_suite_list "${tmp_test_suite_list};${target_name}" CACHE INTERNAL "")
    else()
        set(test_suite_list "${target_name}" CACHE INTERNAL "")
    endif()

endfunction(create_test_suite)

function(add_files_under_test target_name)
    set(file_list ${ARGN})
    foreach(file ${file_list})
        get_filename_component(file_dir "${file}" DIRECTORY)
        get_filename_component(file_name "${file}" NAME)

        file(COPY ${SOURCE_CODE}/${file} DESTINATION ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file_dir})

        if(${file_name} MATCHES "\\.h$|\\.hpp$")
            target_include_directories(${target_name} PRIVATE ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file_dir})
        endif()

        if(${file_name} MATCHES "\\.c$|\\.cpp$")
            target_sources(${target_name} PRIVATE ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file})
            file(TO_NATIVE_PATH "${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file}" native_filter_path)

            if(EXISTS ${CMAKE_BINARY_DIR}/gcovr.cfg)
                file(APPEND ${CMAKE_BINARY_DIR}/gcovr.cfg "filter=${native_filter_path}\n")
            else()
                file(WRITE ${CMAKE_BINARY_DIR}/gcovr.cfg "filter=${native_filter_path}\n")
            endif()
        endif()

    endforeach()
endfunction(add_files_under_test)
