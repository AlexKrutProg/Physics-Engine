cmake_minimum_required(VERSION 3.7)
project(Demo)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES BubbleComponent.cpp BubbleComponent.h main.cpp)

add_executable(Demo ${SOURCE_FILES})

add_subdirectory(Engine)
target_link_libraries(Demo Engine)
