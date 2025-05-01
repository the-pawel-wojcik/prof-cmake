cmake_minimum_required(VERSION 3.30)
project(PPrint LANGUAGES C CXX)

add_executable(MyApp main.c)
add_executable(MyAlias ALIAS MyApp)
add_library(MyLib STATIC src.cpp)
include(CMakePrintHelpers)
cmake_print_properties(TARGETS MyApp MyLib MyAlias PROPERTIES TYPE
                                                              ALIASED_TARGET)

set(pretty "Am I pretty")
unset(variable)
include(CMakePrintHelpers)
cmake_print_variables(pretty variable CMAKE_VERSION)
