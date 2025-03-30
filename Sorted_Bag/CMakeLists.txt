cmake_minimum_required(VERSION 3.27)
project(Sorted_Bag)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sorted_Bag App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)