cmake_minimum_required(VERSION 3.27)
project(Matrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(Matrix App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        Matrix.cpp
        Matrix.h
        ShortTest.cpp
        ShortTest.h)