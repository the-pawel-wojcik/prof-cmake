# 15. Build Type
CMake's default build types:
- Debug
- Release
- RelWithDebInfo
- MinSizeRel
The build type is cached
```bash
cmake -D CMAKE_BUILD_TYPE:STRING=Debug
```

## The problem
There are two types of build systems: those that support only single build type
(Make, Ninja), and those that support multi-configuration builds (Xcode, VS).
The second type picks the build type as a *build* flag, while the first type
picks the build as a *configure* flag.
```bash
# for multi-configuration builds
cmake -G Xcode -B build -S src
cmake --build build --config Debug
```

Using 
```cmake
if(CMAKE_BUILD_TYPE STREQUAL "Debug")  # Don't do this
```
would only make sense for the single-configuration tools. Instead of
`CMAKE_BUILD_TYPE` rely on 
```cmake
add_compile_definitions($<$<CONFIG:Debug>:MYPROJ_DEBUG>)  # Better
```


## Single-configuration generators
Present the list of supported builds
```cmake
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
        STRINGS Debug Release Profile
)
```
but it only helps if project users use some IDE or other tool for editing the
CMakeCache.txt, it DOES NOT stop the users for setting the value to anything
they want.
