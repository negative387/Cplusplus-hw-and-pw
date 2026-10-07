cmake_minimum_required(VERSION 4.1)
project(26_introduction_to_inheritance)

set(CMAKE_CXX_STANDARD 20)

add_executable(26_introduction_to_inheritance main.cpp
        Pet.cpp
        Pet.h
        Dog.cpp
        Dog.h
        Cat.cpp
        Cat.h
        Parrot.cpp
        Parrot.h
        String.cpp
        String.h
        BitString.cpp
        BitString.h)
