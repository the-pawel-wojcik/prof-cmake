# 7. Flow Control

```cmake
if(expression1)
# commands ...
elseif(expression2)
# commands ...
else()
# commands ...
endif()
```

## What evalues to true?
If value is a quoted or unquoted constant with value `ON`, `YES`, `TRUE`, or
`Y`, it is treated as true. The test is case-insensitive.


## The variable-or-string rule
The `if` statements expand variables before action. For example, if a variable
named `var` is defined before the `if` statement, then the expression `${var}`
is expaned. On top of that, bare strings, like `var`, are also treated as
variables and are expanded. This additional functionality applies only when a
variable of the matching name exists; otherwise, the expression `var` is
treated like a string. One would think that if quoted, `"var"`, would not
experience expansion. This is only since CMake 3.1, for earlier version even a
quoted expression would experience expansion.
