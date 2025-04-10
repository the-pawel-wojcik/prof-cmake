cmake_minimum_required(VERSION 3.20)
project(Loops)

message("\nLooping over a list of items with foreach(var arg1 [arg2...] ):")
foreach(var 1 2 3 5 8 13)
    message(" > The current value is ${var}.")
endforeach()
    

set(fibo 0 1 1 2 3 5 8 13 21)
set(pell 1 2 5 12 29 70 169)

message("\nLooping over a list of items with")
message("\tforeach(var IN LISTS list1 [list2...] [ITEMS item1...]):")
foreach(var IN LISTS fibo pell ITEMS 31)
    if(var EQUAL 13)
        message(" > Skipping 13")
        continue()
    endif()
    message(" > The current value is ${var}.")
endforeach()

# ZIP_LISTS added in CMake 3.17
message("\nLooping over a list of items at the same time")
message("\tforeach(var... IN ZIP_LISTS list1...)")
foreach(fib pel IN ZIP_LISTS fibo pell)
    message(" > The current pair are: ${fib} ${pel}.")
endforeach()

message("\nLooping with RANGE (both start and stop included)")
message("\tforeach(var RANGE start stop [step])")
foreach(var RANGE 0 6 2)
    message(" > The current value is: ${var}.")
endforeach()


message("\nCMake's unexpected behavior #3001:")
message("\tforeach(var RANGE 3) is inclusive at both ends")
foreach(var RANGE 3)
    message(" > The current value is: ${var}.")
endforeach()
