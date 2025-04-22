cmake_minimum_required(VERSION 3.30)
project(functions)

function(print arg)
  message("Printing using the print function:")
  message("\t${arg}")
endfunction()

print("Hi Paweł")

function(func arg)
  if(DEFINED arg)
    message("Function arg is a defined variable")
  else()
    message("Function arg is NOT a defined variable")
  endif()
endfunction()

macro(macr arg)
  if(DEFINED arg)
    message("Macro arg is a defined variable")
  else()
    message("Macro arg is NOT a defined variable")
  endif()
endmacro()

message(
  "The difference between the argument handling of a function and a macro")
func(foobar)
macr(foobar)

message("")
function(funcname named_argument)
    message("The number of arguments: ${ARGC}.")
    message("Value of `named_argument`: ${named_argument}")
    message("Values of the remainig arguments: ${ARGN}")
    message("Values of all arguments: ${ARGV}")
endfunction()

funcname(CMake a Beautiful Language)
message("")

add_subdirectory("keywords_parsing")
add_subdirectory("returning_value")
add_subdirectory("using_source_file")
