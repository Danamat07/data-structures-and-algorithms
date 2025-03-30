cmake_minimum_required(VERSION 3.27)
project(Sorted_MultiMap)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorted_MultiMap App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        SMMIterator.cpp
        SMMIterator.h
        ShortTest.cpp
        ShortTest.h
        SortedMultiMap.cpp
        SortedMultiMap.h)