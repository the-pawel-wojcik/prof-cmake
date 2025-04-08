cmake_minimum_required(VERSION 3.5)
project(Variables)

set(
    ShellScript 
    [==[
#!/bin/bash

[[ -n "${USER}" ]] && echo "Have ${USER}"]==]
)

message("\n\nPrinting variable ShellScript.")
message(${ShellScript})
message("End of printing.")

message("\n\nPrint and set vars:")
set(x 1)
message("x is set to ${x}")
set(x 2)
message("x is set to ${x}")
set(x 3)
message("x is set to ${x}")
message("\n\n")

message("The string(FIND) call examples")
# FIND input stringToFind outVar
string(FIND abcdefabcdef def fwdIndex)
string(FIND abcdefabcdef def revIndex REVERSE)
string(FIND abcdefabcdef XXX noIndex)
message("fwdIndex = ${fwdIndex}\n"
"revIndex = ${revIndex}\n"
"noIndex = ${noIndex}")
# REPLACE matchString replaceWith outVar input...
message("\n Replace")
string(REPLACE def XXXXX result abcdefabcdef)
message("result = ${result}")

message("\n regex")
string(REGEX MATCH "[de]" matchOne abcdefabcdef)
string(REGEX MATCHALL "[de]" matchAll abcdefabcdef)
string(REGEX REPLACE "([de]+)" "X\\1Y" replaced abcdefabcdef)

message("matchOne = ${matchOne}\n"
"matchAll = ${matchAll}\n"
"replaced = ${replaced}")

message("\n substring")
# SUBSTRING input index length outVar
# A length of -1 means to the end of the string.
string(SUBSTRING abcdefabcdef 4 2 result1)
string(SUBSTRING abcdefabcdef 4 -1 result2)
message("result1 = ${result1}\n"
"result2 = ${result2}")

message("\n other")
string(LENGTH aBcDe length)
string(LENGTH Paweł pawelLength)
string(TOLOWER aBcDe lower)
string(TOUPPER aBcDe upper)
string(STRIP " aBcDe " stripped)
message(
    "length = ${length}\n"
    "pawelLength = ${pawelLength}\n"
    "lower = ${lower}\n"
    "upper = ${upper}\n"
    "stripped = '${stripped}'"
)


set(myList a b c)
# Creates the list "a;b;c"
# Last argument names the variable to store the result in
list(LENGTH myList len)
list(GET myList 2 1 letters)
list(FIND myList c index)
list(JOIN myList "***" joined)
message("length = ${len}\n"
"letters = ${letters}\n"
"index = ${index}\n"
"joined = ${joined}")


message("\n In place editing")
message("myList = ${myList}")
# These operations all modify the list directly in-place
list(INSERT myList 2 X Y Z)
message("myList (INSERT 2 X Y Z) = ${myList}")
list(APPEND myList d e f)
message("myList (APPEND d e f) = ${myList}")
# CMake 3.15 or later required
list(PREPEND myList P Q R)
message("myList (PREPEND P Q R) = ${myList}")

message("\n In place deleting")
set(myList a b c d e f g a b c d e f g)
message("myList = ${myList}")
# These operations all modify the list directly in-place.
list(REMOVE_ITEM myList d)
message("list(REMOVE_ITEM myList d) = ${myList}")
list(REMOVE_AT myList 1)
message("list(REMOVE_AT myList 1) = ${myList}")
list(REMOVE_DUPLICATES myList)
message("list(REMOVE_DUPLICATES myList) = ${myList}")

message("\n Popping")
set(myList a b c d e f g)
# These operations all modify the list directly in-place.
# CMake 3.15 or later is also required.
list(POP_BACK myList last secondLast)
message("myList (POP_BACK) = ${myList}\n"
"last = ${last}\n"
"secondLast = ${secondLast}")
list(POP_FRONT myList first second)
message("myList (POP_FRONT) = ${myList}\n"
"first = ${first}\n"
"second = ${second}")

message("\n Math")
set(x 3)
set(y 7)
math(EXPR zDec "(${x}+${y}) * 2")
message("decimal = ${zDec}")
# Requires CMake 3.13 or later for HEXADECIMAL
math(EXPR zHex "(${x}+${y}) * 2" OUTPUT_FORMAT HEXADECIMAL)
message("hexadecimal = ${zHex}")

message("\n Cache variable of type PATH")
set(armadillo_root /opt/armadillo CACHE PATH "Armadillo installation root.")
message("armadillo_root = ${armadillo_root}")
