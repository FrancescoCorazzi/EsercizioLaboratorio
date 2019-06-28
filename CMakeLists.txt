cmake_minimum_required(VERSION 3.14)
project(EsLaboratorio)

set(CMAKE_CXX_STANDARD 17)

add_executable(EsLaboratorio main.cpp BankAccount.cpp BankAccount.h Transaction.cpp Transaction.h AccountDatabase.cpp AccountDatabase.h)