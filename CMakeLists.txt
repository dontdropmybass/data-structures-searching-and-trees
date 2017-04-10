cmake_minimum_required(VERSION 3.7)
project(data_structures_searching_and_trees)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp search.cpp search.h bst.cpp bst.h filehandler.cpp filehandler.h avl.cpp avl.h)
add_executable(data_structures_searching_and_trees ${SOURCE_FILES})