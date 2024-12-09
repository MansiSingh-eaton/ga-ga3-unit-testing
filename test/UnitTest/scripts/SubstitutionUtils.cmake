cmake_minimum_required(VERSION 3.5)

include(${UNIT_TEST_ROOT}/scripts/GlobUtils.cmake)

function(substitute_files substitute_type target_name)
    set(file_list ${ARGN})
    foreach(file ${file_list})
        get_filename_component(file_dir "${file}" DIRECTORY)
        get_filename_component(file_name "${file}" NAME)

        # Debug message to print the source and destination paths
        message(STATUS "Copying file from ${UNIT_TEST_ROOT}/${substitute_type}/${file} to ${CMAKE_BINARY_DIR}/GLOB/${target_name}/${file_dir}")
        file(COPY ${UNIT_TEST_ROOT}/${substitute_type}/${file} DESTINATION ${CMAKE_BINARY_DIR}/GLOB/${target_name}/${file_dir})

        if(${file_name} MATCHES "\\.h$|\\.hpp$")
            target_include_directories(${target_name} PRIVATE ${CMAKE_BINARY_DIR}/GLOB/${target_name}/${file_dir})
        endif()

        if(${file_name} MATCHES "\\.c$|\\.cpp$")
            target_sources(${target_name} PRIVATE ${CMAKE_BINARY_DIR}/GLOB/${target_name}/${file})
        endif()

    endforeach()
endfunction()

function(substitute_mock_files target_name)
    substitute_files(mocks ${target_name} ${ARGN})
endfunction()

function(include_source_files target_name)
    set(file_list ${ARGN})
    foreach(file ${file_list})
        get_filename_component(file_dir "${file}" DIRECTORY)
        get_filename_component(file_name "${file}" NAME)

        # Debug message to print the source and destination paths
        message(STATUS "Copying file from ${SOURCE_CODE}/${file} to ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file_dir}")
        file(COPY ${SOURCE_CODE}/${file} DESTINATION ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file_dir})

        if(${file_name} MATCHES "\\.h$|\\.hpp$")
            target_include_directories(${target_name} PRIVATE ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file_dir})
        endif()

        if(${file_name} MATCHES "\\.c$|\\.cpp$")
            target_sources(${target_name} PRIVATE ${CMAKE_BINARY_DIR}/GLOB/${target_name}/src/${file})
        endif()

    endforeach()
endfunction()


