cmake_minimum_required(VERSION 3.14)
project(CSCI3132_Project)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
        Character.cpp
        Character.h
        )

add_executable(CSCI3132_Project main.cpp ${SOURCE_FILES} ${SOURCES})