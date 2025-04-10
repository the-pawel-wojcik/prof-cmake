cmake_minimum_required(VERSION 3.30)
project(ControlFlow)

if(yes-NotFound)
    message("This message won't ever be printed.")
elseif(yEs)
    message("yEs evalues to true.")
else()
    message("else() comes with a pari of parenthesis.")
endif()

# No variable named "a" is defined, so it is treated as a string with value "a"
if(a STREQUAL "there")
    message("We do not get here")
elseif(a STREQUAL "")
    message("We do not get here either")
endif()

set(a there)
# Now there is a variable named "a", so its value is used.
if(a STREQUAL "there")
    message("")
    message(
        " if(a STREQUAL \"there\") expands the variable `a` before comparison."
    )
endif()

message("")
if ("/a//b/c" PATH_EQUAL "/a/b/c")
    message(
        " if (\"/a//b/c\" PATH_EQUAL \"/a/b/c\") evalues to True"
        "\nwhile\n"
        " if (\"/a//b/c\"  STREQUAL  \"/a/b/c\") evalues to False\n"
    )
endif()
if ("/a//b/c" STREQUAL "/a/b/c")
   # We do NOT get here...
endif()


message("\n CMake's regex")
set(who "Paweł Wójcik")
set(regex "(.+)")  # This one works
set(regex "([:alpha:]+)")
if("Hi from ${who}" MATCHES "Hi from ${regex}")
    message("${CMAKE_MATCH_1} says hello.")
else()
    message("${who} didn't match ${regex}")
endif()

# There are filesystem test!
# CMake exception #410: 
#   none of these perform the variable expansion outside of ${}
message([[
if(EXISTS pathToFileOrDir)
if(IS_READABLE pathToFileOrDir)    # 3.29+
if(IS_WRITABLE pathToFileOrDir)    # 3.29+
if(IS_EXECUTABLE pathToFileOrDir)  # 3.29+
if(IS_DIRECTORY pathToDir)
if(IS_SYMLINK fileName)
if(IS_ABSOLUTE path)
if(file1 IS_NEWER_THAN file2)
]])

# The IS_NEWER_THAN works different from what is sounds like
# WARNING: Very likely to be wrong
if(${firstFile} IS_NEWER_THAN ${secondFile})
    # ... commands to recreate secondFile
endif()

# Do instead:
set(firstFile "CMakeLists.txt")
set(secondFile "/full/path/to/another/file")
if(NOT EXISTS ${firstFile})
    message(FATAL_ERROR "${firstFile} is missing")
elseif(
    NOT EXISTS ${secondFile} OR
    NOT ${secondFile} IS_NEWER_THAN ${firstFile}
)
    # ... commands to recreate secondFile
    message("Recreating second file.")
endif()

if(DEFINED ENV{LD_LIBRARY_PATH})
    message("\nEnvironmental variable found:")
    message("  LD_LIBRARY_PATH = $ENV{LD_LIBRARY_PATH}")
endif()
