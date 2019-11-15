cmake_minimum_required(VERSION 3.14)
project(project7_PennWarren)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project7_PennWarren
    Data.cpp
    Data.h
    Day.cpp
    Day.h
    Queue.h
    Queue.cpp
    LinkedList.h
    LinkedList.cpp
    SortedLinkedList.h
    SortedLinkedList.cpp
    Stack.h
    Stack.cpp
    main.cpp
        )
