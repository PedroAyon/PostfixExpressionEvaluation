cmake_minimum_required(VERSION 3.28)
project(MathExpressionSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(MathExpressionSolver main.cpp
        Stack.cpp
        Stack.h
        Node.cpp
        Node.h)
