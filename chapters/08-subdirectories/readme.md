# 8. Using Subdirectories

## `add_subdirectory`
The first way to do it is with 
```cmake
add_subdirectory(src_subdir [sub_builddir])
```
The `sub_builddir` is compulsory only for `src_subdir` pointing outside the
source tree.

Here are a handful of `cmake`'s read-only, automatically updated variables.
```cmake
message("${CMAKE_SOURCE_DIR} holds the top-most of the *source*-tree.")
message("${CMAKE_BINARY_DIR} holds the top-most of the *build*-tree.")
message("There are also the local versions of these variables.")
message("*_CURRENT_* variables store the directory currently processed.")
message("${CMAKE_CURRENT_SOURCE_DIR}")
message("${CMAKE_CURRENT_BINARY_DIR}")
```

## Scopes
The `add_subdirectory` command works like the `block()` command. A new scope
inherits a *copy* of the calling `CMakeLists.txt`'s variables. Copies of the
callers variables are visible and can be tweaked but nothing comes back to the
caller.

UNLESS the subdirectory uses
```cmake
set(var value PARENT_SCOPE)
```

## `include`
The other command for including subdirectories has the following syntax
```cmake
include(fileName [OPTIONAL] [RESULT_VARIABLE myVar] [NO_POLICY_SCOPE])
```
Diffs 
- file (.cmake) not a directory
- no new scope!
- enables deactivation of new policy scope
- `CMAKE_CURRENT_SOURCE_DIR` and `CMAKE_CURRENT_BINARY_DIR` don't change

There is also the other function wiht the same name
```cmake
include(module   [OPTIONAL] [RESULT_VARIABLE myVar] [NO_POLICY_SCOPE])
```
but this will be covered in chapter 12.

The variable `CMAKE_CURRENT_LIST_DIR` does the job of
`CMAKE_CURRENT_SOURCE_DIR` but for `include()`. Additionally
```cmake
${CMAKE_CURRENT_LIST_FILE}  # Always shows currently procesesd file name.
${CMAKE_CURRENT_LIST_LINE}  # processed line of ${CMAKE_CURRENT_LIST_FILE}
```

## Sourcing trap
The `${CMAKE_SOURCE_DIR}` variable acts goofy if the project for which it was
developed becomes just an addon for a larger project. The `${PROJECT_}`
variables come to rescue. If a `project()` is called at least once the
following new variables become available.
```cmake
${PROJECT_SOURCE_DIR}
${PROJECT_BINARY_DIR}

${projectName_SOURCE_DIR}
${projectName_BINARY_DIR}
```

### Trick
Check if you are at the top of the tree.
```cmake
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    add_subdirectory(packaging)
endif()
# The one below requires CMake 3.21 or later
if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(packaging)
endif()
```
Other variable available since 3.21 is `<projectName>_IS_TOP_LEVEL`

## `return`
CMake has a return statement that exits the current block. The return statement
accepts arugment which enables overwriting variables in the parent scope.
```cmake
set(x 5)
set(y 1)
block()
    set(x 1)
    unset(y)
    return(PROPAGATE x y)
endblock()
```

### Avoid multiple runs of a file
If some section of a code cannot run more than once there is a guard mechanism
that can stop it
```cmake
include_guard()
```
You can call `include_guard()` at the beginning of your CMake file (usually a
`.cmake` file). If this file is included multiple times in a single CMake
configure run, the commands in the file will only be executed once.

Before cmake 3.10 people would use
```cmake
if(DEFINED cool_stuff_include_guard)
    return()
endif()
set(cool_stuff_include_guard 1)
```
