cmake_minimum_required(VERSION 3.16)
project(community_detection_AI)

set(CMAKE_CXX_STANDARD 14)

add_executable(community_detection_AI main.cpp Population.h Population.cpp Individual.h Individual.cpp Graph.h Graph.cpp)