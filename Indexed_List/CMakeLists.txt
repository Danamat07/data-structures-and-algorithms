cmake_minimum_required(VERSION 3.27)
project(Indexed_List)

set(CMAKE_CXX_STANDARD 17)

add_executable(Indexed_List App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IndexedList.cpp
        IndexedList.h
        ShortTest.cpp
        ShortTest.h
        ListIterator.cpp
        ListIterator.h)