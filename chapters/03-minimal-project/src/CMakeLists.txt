#[[
Lua-styled
comments
work
in
CMake
since
3.0
]]

cmake_minimum_required(VERSION 3.30)

project(
    MyApp
    VERSION 0.0.1
    LANGUAGES CXX
)

add_executable(MyExe main.cpp)
