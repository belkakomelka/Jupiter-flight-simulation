cmake_minimum_required(VERSION 3.26)
project(Jupiter-flight-simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Jupiter-flight-simulation main.cpp
        iterSystemSolver/iterSystemSolver.cpp
        gauss/gauss.cpp
        Modyfied_Newton/Modyfied_Newton.cpp
        RK4/RK4.cpp
        Modyfied_Newton/EuclideanNorm.cpp
        Modyfied_Newton/LocalNorm.h
        Modyfied_Newton/LocalNorm.cpp
        residuals/residuals.cpp)
