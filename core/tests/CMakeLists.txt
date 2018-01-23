
SET( syntactic_tests ${PROJECT_SOURCE_DIR}/tests/resources/syntactic )
SET( semantic_tests ${PROJECT_SOURCE_DIR}/tests/resources/semantic )
SET( validation_tests ${PROJECT_SOURCE_DIR}/tests/resources/validation )

file(GLOB files "${semantic_tests}/*.csvs")
foreach(file ${files})
    get_filename_component(filename ${file} NAME )
    configure_file(${semantic_tests}/${filename} ${PROJECT_BINARY_DIR}/tests/resources/semantic/${filename} COPYONLY)
endforeach()

file(GLOB files "${syntactic_tests}/*.csvs")
foreach(file ${files})
    get_filename_component(filename ${file} NAME )
    configure_file(${syntactic_tests}/${filename} ${PROJECT_BINARY_DIR}/tests/resources/syntactic/${filename} COPYONLY)
endforeach()

file(GLOB files "${validation_tests}/*.csvs")
foreach(file ${files})
    get_filename_component(filename ${file} NAME )
    configure_file(${validation_tests}/${filename} ${PROJECT_BINARY_DIR}/tests/resources/validation/${filename} COPYONLY)
    message(STATUS "Copying: ${filename}")
endforeach()

# configure_file(${syntactic_tests}/any.csvs ${PROJECT_BINARY_DIR}/tests/resources/syntactic/any.csvs COPYONLY)

add_executable(mytests test.cpp ${include_dir_list} ${antlr4cpp_src_files_schemaparser} ../include/CustomErrorListener.h
        semanticTests.cpp ../include/Context.h ../src/Context.cpp ../src/Nodes.cpp validationTests.cpp)
add_dependencies(mytests antlr4cpp antlr4cpp_generation_schemaparser validator)
target_link_libraries(mytests antlr4-runtime validator gmock_main -pthread -lstdc++fs)
add_test(MyTests mytests)