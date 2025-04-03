cmake_minimum_required(VERSION 3.30)

project(
    MyApp
    VERSION 0.0.1
    LANGUAGES CXX
)

add_executable(
    MyExe 
    WIN32  # ignored on non-Windows
    MACOSX_BUNDLE  # Works for Apple's OSes
    main.cpp
)

# Extra tools excluded from the ALL target
add_executable(reporter EXCLUDE_FROM_ALL reporter.cpp)

# The type of library is usually not specified in the add_library but instead
# is dictated by variables
# set(BUILD_SHARED_LIBS YES)  # like this one
# but mainly used from the command line by the user
add_library(mylib
    # [STATIC | SHARED | MODULE]
    EXCLUDE_FROM_ALL
    mylib.cpp
)

# reporter uses mylib internally
target_link_libraries(reporter PRIVATE mylib)
