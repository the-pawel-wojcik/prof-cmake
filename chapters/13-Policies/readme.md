# 13. Policies
The `cmake_minimum_required(VERSION num)` call, not only requires the minimum
version of CMake, but also sets the policies to match that version.

The similar `cmake_policy(VERSION major[.minor[.patch[.tweak]]])` command
exists. A use for this would be as follows
```cmake
cmake_minimum_required(VERSION 3.14)
project(Modern)

# Do 3.14 stuff

# import an old dependency
cmake_policy(VERSION 2.6)
add_subdirectory(oldProject)
```

Each policy can be controlled individually with
```cmake
cmake_policy(SET CMPxxxx NEW)
```

Two way of doing policy contex managers
```cmake
# Requires CMake 3.25 or later
block(SCOPE_FOR POLICIES)
    # Make changes to policies here. Policy settings outside
    # the block are not affected.
endblock()
# Works with any CMake version
cmake_policy(PUSH)
    # Make changes to policies here. Policy changes apply
    # up until the policy stack is popped (see below).
cmake_policy(POP)
```
The first option is better as it calls the descructor as soon as the execution
exits the block.

Some commands, including `add_subdirectory`, `include`, and `find_package`,
automatically push to the policy stack and pop before returning to the caller.
