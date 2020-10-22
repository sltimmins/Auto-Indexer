cmake_minimum_required(VERSION 3.14)
project(20f-auto-idx)
set (EXE_NAME indexer)

##########################################
# Students, edit the items below.  In the quotes,
# put the names of the input files as they should appear
# in the argv param to main.
# Example:
#   set (input01 "train_data.csv")
#   set (input02 "train_target.csv")
# etc....

set (input01 "input03.txt")

#
##########################################

# Copy data files to build dir
foreach(file IN LISTS input01 input02 input03 input04)
    configure_file(${file} ${file} COPYONLY)
endforeach()

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS_DEBUG "-O3")
add_executable(${EXE_NAME} main.cpp DSVector.h vectorTest.cpp catch.hpp LinkedListTest.cpp DSString.cpp DSString.h DSLinkedList.h Indexer.h Parser.h Entry.h Parser.cpp Entry.cpp)
