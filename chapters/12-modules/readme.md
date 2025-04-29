# 12. Modules
The CMakes standard and external libraries.

Syntax
```cmake
include(
    module # looks for module.cmake (case-sensitive)
    [OPTIONAL]
    [RESULT_VARIABLE myVar]
    [NO_POLICY_SCOPE]
)
```

Use `cmake/` to store your local modules. To make CMake look into that
directory add
```cmake
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
```
to you `CMakeLists.txt` before you start calling `include`.

The `find_package(Name)` imports cmake files similar to `include` but instead
of searching for `name.cmake`, it looks for `FindName.cmake`.

## Check modules
```cmake
include(CheckSourceCompiles)
check_source_compiles(lang code resultVar
    [FAIL_REGEX regexes...]
    [SRC_EXT extension]
)
```
the `resultVar` holds the outcome of the test. It is a cached variable. The
variable is not refreshed even in the tested code changes. To update this
variable it needs to be manually removed from the cache.

To check if built program runs, CMake provides
```cmake
include(CheckSourceRuns)
check_source_runs(lang code resultVar
    [SRC_EXT extension]
)
```

Other checks
```cmake
include(CheckCompilerFlag)
check_compiler_flag(lang flag resultVar)
```
any warning fails the test.

Instead of playing with `CMAKE_REQUIRED_LINK_OPTIONS` in
`check_source_compiles`, CMake 3.18 offers a shortcut
```cmake
include(CheckLinkerFlag)
check_linker_flag(language flag resultVar)
```

For C and C++ one can even check if symbols exist
```cmake
include(CheckSymbolExists)
check_symbol_exists(symbol headers resultVar)

include(CheckCXXSymbolExists)
check_cxx_symbol_exists(symbol headers resultVar)
```

Other checks can be found on the [CMake Reference
website](https://cmake.org/cmake/help/latest/manual/cmake-modules.7.html).

A contex manager for the `CMAKE_REQUIRED_...` variables
```cmake
include(CMakePushCheckState)
cmake_push_check_state([RESET])
cmake_pop_check_state()
cmake_reset_check_state()
```
