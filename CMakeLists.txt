cmake_minimum_required(VERSION 3.27)
project(tree_sitter_example)

execute_process(COMMAND make WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/lib/tree-sitter)

add_executable(tree_sitter_example
    main.cpp
    lib/tree-sitter-cpp/src/parser.c
    lib/tree-sitter-cpp/src/scanner.c
    lib/tree-sitter-cpp/src/tree_sitter/parser.h
    lib/tree-sitter-cpp/src/tree_sitter/runtime.h
)
include_directories(lib/tree-sitter/lib/include)

set(CMAKE_CXX_STANDARD 17)

add_library(custom-tree-sitter SHARED IMPORTED)
set_target_properties(custom-tree-sitter
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/lib/tree-sitter/libtree-sitter.so
)

target_link_libraries(tree_sitter_example custom-tree-sitter)
