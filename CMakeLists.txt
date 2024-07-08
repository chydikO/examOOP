cmake_minimum_required(VERSION 3.28)
project(examOOP)

set(CMAKE_CXX_STANDARD 17)

add_executable(examOOP main.cpp
        Department.cpp
        Department.h
        Employee.cpp
        Employee.h
        BankAccount.cpp
        BankAccount.h)
