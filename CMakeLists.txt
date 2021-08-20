cmake_minimum_required (VERSION 3.5)

project (FizzBuzz LANGUAGES CXX)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (MSVC)
    string (APPEND CMAKE_CXX_FLAGS " /DEBUG:NONE /O2 /Ob2")
else ()
    string (APPEND CMAKE_CXX_FLAGS " -O3 -g0")
endif ()

add_executable(FizzBuzz main.cpp)
