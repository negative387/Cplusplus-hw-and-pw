cmake_minimum_required(VERSION 4.1)
project(28_polymorphism_and_abstract_classes_and_pure_virtual_functions_hw)

set(CMAKE_CXX_STANDARD 20)

add_executable(28_polymorphism_and_abstract_classes_and_pure_virtual_functions_hw main.cpp
        Equation.cpp
        Equation.h
        LinearEquation.cpp
        LinearEquation.h
        QuadraticEquation.cpp
        QuadraticEquation.h
        Shape.cpp
        Shape.h
        Square.cpp
        Square.h
        Rectangle.cpp
        Rectangle.h
        Circle.cpp
        Circle.h
        Ellipse.cpp
        Ellipse.h)
