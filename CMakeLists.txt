cmake_minimum_required(VERSION 3.26)
project(Projeto_AED)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto_AED main.cpp
        Students.cpp
        Students.h
        Classes.cpp
        Classes.h
        ClassTimeBlock.cpp
        ClassTimeBlock.h
        ClassSchedule.cpp
        ClassSchedule.h
        Management.cpp
        Management.h
        Requests.cpp
        Requests.h)
