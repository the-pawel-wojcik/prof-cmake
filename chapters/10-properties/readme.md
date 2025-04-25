# 10. Properties
One of the driest chapters so far.

The general syntax
```cmake
set_property(entitySpecific
    [APPEND | APPEND_STRING]
    PROPERTY propertyName values...
)
```
Allowed values of `entitySpecific`
```cmake
GLOBAL
DIRECTORY [dir]
TARGET targets...
SOURCE sources...  # extra options CMake 3.18
INSTALL files...
TEST tests...      # extra options CMake 3.28
CACHE vars...
```

There is also a getter
```cmake
get_property(
    resultVar 
    entitySpecific
    PROPERTY propertyName
    [...other keywords...]
)
```
the `get_property` takes extra `VARIABLE` as an allowed `entitySpecific`.

## Specif versions
Other than the generic `get/set_property` most properties have the specialized
versions, i.e., `get_test_property`. Reason why CMake is the ultimate
programming language #951: each of the `get/set_\w\+_property` functions have
at least one argument or default behaviour different for each other.
