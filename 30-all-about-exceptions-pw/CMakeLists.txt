cmake_minimum_required(VERSION 4.1)
project(30_all_about_exceptions_pw)

set(CMAKE_CXX_STANDARD 20)

add_executable(30_all_about_exceptions_pw main.cpp
        LibraryException.cpp
        LibraryException.h
        BookNotFoundException.cpp
        BookNotFoundException.h
        BookUnavailableException.cpp
        BookUnavailableException.h
        UserNotFoundException.cpp
        UserNotFoundException.h
        OverdueException.cpp
        OverdueException.h
        Library.cpp
        Library.h)
