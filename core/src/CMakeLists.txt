
add_library( validator STATIC Validator.cpp ${antlr4cpp_src_files_schemaparser} Listener.cpp CustomErrorListener.cpp
        Error.cpp SyntaxError.cpp Context.cpp Nodes.cpp)
add_executable( test_antlr main.cpp ${antlr4cpp_src_files_schemaparser} Listener.cpp CustomErrorListener.cpp Error.cpp
        SyntaxError.cpp Context.cpp Nodes.cpp)
add_dependencies( test_antlr antlr4cpp antlr4cpp_generation_schemaparser )
target_link_libraries( test_antlr antlr4-runtime validator )

