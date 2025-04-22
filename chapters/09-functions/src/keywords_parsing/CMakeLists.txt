message("\n Inside ${CMAKE_CURRENT_LIST_DIR}")
message(" Demonstration of function arguments parser.\n")

function(func)
  # Define the supported set of keywords
  set(noValues ENABLE_NET COOL_STUFF)
  set(singleValues TARGET)
  set(multiValues SOURCES IMAGES)

  # Process the arguments passed in
  include(CMakeParseArguments)
  cmake_parse_arguments(arg "${noValues}" "${singleValues}" "${multiValues}"
                        ${ARGN})

  # Log details for each supported keyword
  message("Option summary:")
  foreach(opt IN LISTS noValues)
    if(arg_${opt})
      message(" ${opt} enabled")
    else()
      message(" ${opt} disabled")
    endif()
  endforeach()
  foreach(opt IN LISTS singleValues multiValues)
    # Single argument values will print as a string Multiple argument values
    # will print as a list
    message(" ${opt} = ${arg_${opt}}")
  endforeach()
endfunction()

func(
    SOURCES foo.cpp bar.cpp 
    TARGET MyApp 
    ENABLE_NET
)

func(COOL_STUFF
  TARGET dummy
  IMAGES here.png there.png gone.png
)
