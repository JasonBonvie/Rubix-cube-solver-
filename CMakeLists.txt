cmake_minimum_required(VERSION 3.6)
project(teamProject)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        RubixCube/INode.hpp
        RubixCube/Input.cpp
        RubixCube/Input.hpp
        RubixCube/Output.cpp
        RubixCube/Output.hpp
        RubixCube/RCube.cpp
        RubixCube/RCube.hpp
        RubixCube/RCubeSolver.cpp
        RubixCube/RCubeSolver.hpp
        RubixCube/rubix.cpp
        RubixCube/ShiftArray.cpp
        RubixCube/ShiftArray.hpp
        input.cpp
        input.h
        structures.cpp
        structures.h)

add_executable(teamProject ${SOURCE_FILES})