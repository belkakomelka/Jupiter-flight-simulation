cmake_minimum_required(VERSION 3.26)
project(Jupiter-flight-simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(Jupiter-flight-simulation main.cpp
        iterSystemSolver.h
        iterSystemSolver.cpp
        gauss.h
        gauss.cpp
        Modyfied_Newton.h
        Modyfied_Newton.cpp
        RK4.h
        RK4.cpp
        EuclideanNorm.h
        EuclideanNorm.cpp
        LocalNorm.h
        LocalNorm.cpp
        Subfunction.h
        Subfunction.cpp
        constants.h
        constants.cpp
)
