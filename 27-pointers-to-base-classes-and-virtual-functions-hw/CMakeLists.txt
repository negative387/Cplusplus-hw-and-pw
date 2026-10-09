cmake_minimum_required(VERSION 4.1)
project(27_pointers_to_base_classes_and_virtual_functions_hw)

set(CMAKE_CXX_STANDARD 20)

add_executable(27_pointers_to_base_classes_and_virtual_functions_hw main.cpp
        FilePrinter.cpp
        FilePrinter.h
        FilePrinterASCII.cpp
        FilePrinterASCII.h
        FilePrinterBinary.cpp
        FilePrinterBinary.h)
