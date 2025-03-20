cmake_minimum_required(VERSION 3.10.0)
project(cpu-raytracing-part-i VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp src/*.h)

add_executable(
    ${PROJECT_NAME} 
    ${SRC_FILES}
)