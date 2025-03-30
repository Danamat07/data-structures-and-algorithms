cmake_minimum_required(VERSION 3.27)
project(Map)

set(CMAKE_CXX_STANDARD 17)

add_executable(Map App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Map.cpp
        Map.h
        MapIterator.cpp
        MapIterator.h
        ShortTest.cpp
        ShortTest.h)