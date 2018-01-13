
SET( syntactic_tests ${PROJECT_SOURCE_DIR}/tests/resources/syntactic)

file(GLOB files "${syntactic_tests}/*.csvs")
foreach(file ${files})
    get_filename_component(filename ${file} NAME )
    configure_file(${syntactic_tests}/${filename} ${PROJECT_BINARY_DIR}/tests/resources/syntactic/${filename} COPYONLY)
endforeach()

# configure_file(${syntactic_tests}/any.csvs ${PROJECT_BINARY_DIR}/tests/resources/syntactic/any.csvs COPYONLY)

add_executable(mytests test.cpp ${include_dir_list} ${antlr4cpp_src_files_schemaparser} ../src/CustomErrorListener.cpp ../include/CustomErrorListener.h)
add_dependencies(mytests antlr4cpp antlr4cpp_generation_schemaparser validator)
target_link_libraries(mytests antlr4-runtime validator gmock_main -pthread)
add_test(MyTests mytests)