cmake_minimum_required(VERSION 3.17)

list(APPEND CMAKE_MESSAGE_CONTEXT Coolio)

project(Coolio LANGUAGES CXX)
message("Adding features\nHere we go:")
add_subdirectory(networking)
add_subdirectory(graphics)
message("All done")
