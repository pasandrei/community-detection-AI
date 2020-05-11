cmake_minimum_required(VERSION 3.15)
project(community_detection_AI)

set(CMAKE_CXX_STANDARD 14)

set(GCC_COVERAGE_COMPILE_FLAGS "-O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(community_detection_AI main.cpp Graph.h Graph.cpp Individual.h Individual.cpp Population.h Population.cpp KMeans.h KMeans.cpp Evaluator.cpp Evaluator.h)