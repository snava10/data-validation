project("data-validation")

cmake_minimum_required(VERSION 3.5)
SET (CMAKE_CXX_STANDARD 11)

enable_testing()

### include and libraries ###

set( include_dir_list ${CMAKE_CURRENT_SOURCE_DIR}/include )
# SET( include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include )
include_directories( ${include_dir_list} )
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

### include and libraries ###

### ANTLR setup ###

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/antlr-cmake )
# set variable pointing to the antlr tool that supports C++
set(ANTLR4CPP_JAR_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/antlr4/antlr-4.7.1-complete.jar)
# add external build for antlrcpp
include( ExternalAntlr4Cpp )
# add antrl4cpp artifacts to project environment
include_directories( ${ANTLR4CPP_INCLUDE_DIRS} )
link_directories( ${ANTLR4CPP_LIBS} )
message(STATUS "Found antlr4cpp libs: ${ANTLR4CPP_LIBS} and includes:${ANTLR4CPP_INCLUDE_DIRS} ")
SET( grammar ${CMAKE_CURRENT_SOURCE_DIR}/ValidationSchema.g4)
# Call macro to add lexer and grammar to your build dependencies.
antlr4cpp_process_grammar(schemaparser schemaparser ${grammar})

# include generated files in project environment
include_directories(${antlr4cpp_include_dirs_schemaparser})

### ANTLR setup ###

add_subdirectory(src)
add_subdirectory(tests)

message( STATUS "completed" )
