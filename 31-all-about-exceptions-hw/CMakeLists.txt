cmake_minimum_required(VERSION 4.1)
project(31_all_about_exceptions_hw)

set(CMAKE_CXX_STANDARD 20)

add_executable(31_all_about_exceptions_hw main.cpp
        AccountException.cpp
        AccountException.h
        InvalidAmountException.cpp
        InvalidAmountException.h
        InsufficientFundsException.cpp
        InsufficientFundsException.h
        LimitExceededException.cpp
        LimitExceededException.h
        BankAccount.cpp
        BankAccount.h)
