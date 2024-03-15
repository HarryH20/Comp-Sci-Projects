cmake_minimum_required(VERSION 3.24)
project(proj5_BUAthletes)

set(CMAKE_CXX_STANDARD 17)

add_executable(proj5_BUAthletes proj5-NCAAAthlete.hpp proj5-NCAAAthlete.cpp proj5-BUAthlete.hpp  cmake-build-debug/proj5-BUAthlete.cpp proj5-BUAthleteList.hpp cmake-build-debug/proj5-BUAthleteList.cpp cmake-build-debug/proj5-testmain.cpp cmake-build-debug/proj5-main.cpp proj5-NCAAAthlete.csv proj5-BUAthlete.csv)
