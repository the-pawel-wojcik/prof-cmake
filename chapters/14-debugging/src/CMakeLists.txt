cmake_minimum_required(VERSION 3.30)
project(PrettyPrinting)

function(funcA)
    list(APPEND CMAKE_MESSAGE_INDENT " ")
    message("${CMAKE_CURRENT_FUNCTION}")
endfunction()

function(funcB)
    list(APPEND CMAKE_MESSAGE_INDENT " ")
    message("${CMAKE_CURRENT_FUNCTION}")
    funcA()
endfunction()

function(funcC)
    list(APPEND CMAKE_MESSAGE_INDENT " ")
    message("${CMAKE_CURRENT_FUNCTION}")
    funcB()
endfunction()

message("Top level")
funcA()
funcB()
funcC()
