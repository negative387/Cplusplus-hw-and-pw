cmake_minimum_required(VERSION 4.1)
project(24_association_and_dependency_of_objects_hw)

set(CMAKE_CXX_STANDARD 20)

add_executable(24_association_and_dependency_of_objects_hw main.cpp
        Order.cpp
        Order.h
        Courier.cpp
        Courier.h
        Dough.cpp
        Dough.h
        Pizza.cpp
        Pizza.h)
