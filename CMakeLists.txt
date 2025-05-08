cmake_minimum_required(VERSION 3.31)
project(Credit_Account)

set(CMAKE_CXX_STANDARD 20)

add_executable(Credit_Account main.cpp
        Accounts.h
        Accounts.cpp
        CheckingAccount.h
        CheckingAccount.cpp
        SavingsAccount.h
        SavingsAccount.cpp
)
