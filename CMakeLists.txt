cmake_minimum_required(VERSION 3.26)
project(Jupiter-flight-simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Jupiter-flight-simulation main.cpp
        iterSystemSolver.cpp
        gauss.cpp
        Modyfied_Newton.cpp
        RK4.cpp
        EuclideanNorm.cpp
        LocalNorm.h
        LocalNorm.cpp
        residuals.cpp
        Subfunction.h
        Subfunction.cpp)
