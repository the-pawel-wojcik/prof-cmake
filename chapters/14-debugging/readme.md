# 14. Debugging and Diagnostics

CMake supports printf debugging
```cmake
message([mode] msg1 [msg2]...)
```
Mode options are: `FATAL_ERROR`, `SEND_ERROR`, `WARNING`, `AUTHOR_WARNING`,
`DEPRECATION`, `NOTICE` (default), `STATUS`, `VERBOSE`, `DEBUG`, `TRACE`.

Messaged with mode >= `NOTICE` go to stderr, the rest goes to stdout. 

By default not all messages are displayed. The output level can be controlled
with
```cmake
cmake -S src -B build --log-level LEVEL
```

If project defines `CMAKE_MESSAGE_CONTEXT` it can be viewed with
```bash
cmake -S src -B build --log-contex
```

The `message` command also accepts "checks". The same syntax as before except
`mode` are now one of `CHECK_START`, `CHECK_PASS`, `CHECK_FAIL`. All "checks"
go to the output with `STATUS` log-level.

## Colors
Set the `CMAKE_COLOR_DIAGNOSTICS` variable
```cmake
set(CMAKE_COLOR_DIAGNOSTICS True)
```
to make sure you see compiler errors in their natural colors.

## Pretty Printing
The module `CMakePrintHelpers` contains pretty printing and debugging tools.
```cmake
cmake_print_properties(
[TARGETS target1 [target2...]]
[SOURCES source1 [source2...]]
[DIRECTORIES dir1 [dir2...]]
[TESTS test1 [test2...]]
[CACHE_ENTRIES var1 [var2...]]
PROPERTIES property1 [property2...]
)
```

## Watch
Log all reads and writes to a variable
```cmake
variable_watch(myVar [command])
```

## Profiling
CMake can profile itself.
```bash
cmake --profiling-format=google-trace --profiling-output=fileName.json
```
View the output at [ui.perfetto.dev](https://ui.perfetto.dev)

## Restart
If things go awry delete `CMakeCache.txt` and `CMakeFiles` with
```bash
cmake --fresh
```
