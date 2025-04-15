# 6. Variables
Similar to `make`, only one type, i.e., string.
Use variables like in make but curly.

Lua-styled multi-line strings are supported.
```cmake
set(ShellScript [==[
#!/bin/bash

[[ -n "${USER}" ]] && echo "Have ${USER}"
]==]
)
```

Unsetting
```cmake
set(myVar)
unset(myVar)
```

Environment variable have special syntax.
```cmake
set(ENV{PATH} "$ENV{PATH}:/opt/myDir")
```
Persist only the current run of cmake.

The cache variables live longer
```cmake
set(varName value... CACHE BOOL "docstring" [FORCE])
```
`BOOL` is an example of `type`. Other types can be `FILEPATH`, `PATH`,
`STRING`, `INTERNAL`.
By default, already set cache variables are not overwritten. Adding `FORCE` is
necessary to overwrite a set cache variable.
All types are only used by external tools; cmake knows only strings.
`BOOL` are often `ON/OFF`, `TRUE/FALSE`, `1/0`, etc.

`option` was born out of the common need for cache variable of type `BOOL`
```cmake
option(optVar helpString [initialValue])
```

The `-D` file is used to define the cache variables from the command line.
```bash
cmake -D name:type=value
```
The command line value will replace the cached value. However, in the script
the local variable still take precedence over cached variables. This leads to a
behaviour that is the opposite of the one of GNU Make. In GNU Make the
command-line-set variables override the script-set variables.

For `ccmake` or `cmake-gui` you can you
```cmake
mark_as_advanced([CLEAR|FORCE] var1 [var2...])
```

## Scopes
```cmake
set(x 1)
set(y 3)
set(z 3)
block(PROPAGATE z)
    set(x 2 PARENT_SCOPE)
    unset(y PARENT_SCOPE)
    set(z "Hi")
    # x still has the value 1 here
    # y still exists and has the value 3
    # z has the value "Hi". It will get propagated when exiting the block.
endblock()
# x has the value 2 here, y is no longer defined, and z is now "Hi"
```
Signature
```
block([SCOPE_FOR [VARIABLES] [POLICIES]] [PROPAGATE var...])
```
