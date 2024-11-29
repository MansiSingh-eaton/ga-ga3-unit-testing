cmake_minimum_required(VERSION 3.5)

include(${UNIT_TEST_ROOT}/scripts/Glob.cmake)

function(substitute_files substitute_type target_name)

    set(file_list ${ARGN})
    foreach(file ${file_list})
        get_filename_component(file_dir "${file}" DIRECTORY)
        get_filename_component(file_name "${file}" NAME)

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