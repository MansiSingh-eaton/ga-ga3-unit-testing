cmake_minimum_required(VERSION 3.10)


# Usage:
# set(exclude_files "file1.txt" "file2.txt")
# copy_files_except("path/to/source" "path/to/dest" "${exclude_files}")
function(copy_files_except source_dir dest_dir exclude_files)
    # Create the destination directory if it does not exist
    file(MAKE_DIRECTORY ${dest_dir})

    # Get all .h and .hpp files in the source directory
    file(GLOB all_files "${source_dir}/*.h" "${source_dir}/*.hpp")

    # Loop over all files
    foreach(file_path ${all_files})
        # Get the name of the file
        get_filename_component(file_name ${file_path} NAME)

        # Check if the file is in the exclude list
        list(FIND exclude_files ${file_name} index)

        # If the file is not in the exclude list, copy it
        if(${index} EQUAL -1)
            file(COPY ${file_path} DESTINATION ${dest_dir})
        endif()
    endforeach()
endfunction()

# Usage:
# set(files "file1.txt" "file2.txt")
# move_files("path/to/source" "path/to/dest" "${files}")
function(copy_files source_dir dest_dir)
    set (files ${ARGN})
    # Create the destination directory if it does not exist
    file(MAKE_DIRECTORY ${dest_dir})

    # Loop over all files
    foreach(file_name ${files})
        # Construct the full paths to the source and destination files
        set(source_file "${source_dir}/${file_name}")

        # Check if the source file exists
        if(EXISTS ${source_file})
            # Move the file
            file(COPY ${source_file} DESTINATION ${dest_dir})
        else()
            message("Source file does not exist: ${source_file}")
        endif()
    endforeach()
endfunction()