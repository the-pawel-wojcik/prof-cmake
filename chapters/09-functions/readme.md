# Chapter 9. Functions and Macros

## Syntax
```cmake
function(name [arg1 [arg2 [...]]])
    # Function body (i.e. commands) ...
endfunction()

macro(name [arg1 [arg2 [...]]])
    # Macro body (i.e. commands) ...
endmacro()
```
Functions create their own scope, while macros are a text-based copy-paste.

Example
```cmake
function(print arg)
    message(arg)
endfunctin()

print("Hi Paweł")
```

### Variable number of arguments
```cmake
function(funcname named_argument)
    message("The number of arguments: ${ARGC}.")
    message("Value of `named_argument`: ${named_argument}")
    message("Values of the remainig arguments: ${ARGN}")
    message("Values of all arguments: ${ARGV}")
endfunction()
```

## CMake variables available inside functions
Available since CMake 3.17. Mostly for debugging.
```cmake
# name of the function
${CMAKE_CURRENT_FUNCTION}
# path to the file that defined the function
${CMAKE_CURRENT_FUNCTION_LIST_FILE}
# directory containing the file that defined the function
${CMAKE_CURRENT_FUNCTION_LIST_DIR}
# line number at which the function was defined
${CMAKE_CURRENT_FUNCTION_LIST_LINE}
```

## Calling CMake code blocks
Available since 3.18.
```cmake
cmake_language(CALL command [args...])
cmake_language(EVAL CODE code...)
```
Available since 3.19.
```cmake
cmake_language(
    DEFER
    [DIRECTORY dir]
    [...other options for ID management...]
    CALL command [args...]
)
```
commnads queue is executed at the end of the current directory scope. That's
why `DIRECTORY` allows to specify a difference scope.
```cmake
cmake_language(
    DEFER
    DIRECTORY ${CMAKE_SOURCE_DIR}
    CALL message "End of top level processing"
)
```

## Function arguments
Spaces and semicolons separate arguments. So if there are many space there are
many arguments. The two lines below have the same effect
```cmake
someCommand(a   b c)
someCommand(a;;;b;c)
```
Quoting escapes spaces and semicolons
```cmake
someCommand(a "b;c")  # only two arguments
```
CMake's ultimate programming language prperty #5123: "Spaces only act as
argument separators before any variable evaluation is performed."

Quote variable expansion should you wish to pass it as a single argument.

## Skipped section
9.8.3. Special Cases For Argument Expansion
