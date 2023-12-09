cmake_minimum_required(VERSION 3.16)

project(PlantsEvolution_LSystem LANGUAGES CXX)

#Bring the headers, such as Student.h into the project
include_directories(include)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "*.cpp")

#Generate the shared library from the sources
add_library(PlantsEvolution_LSystem INTERFACE ${SOURCES})
