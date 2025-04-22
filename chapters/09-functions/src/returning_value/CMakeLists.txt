cmake_minimum_required(VERSION 3.25)

message("\n Demonstrate returning a value from a function.")
message(" (Available since CMake 3.25)")
function(overwrite outVar)
    message("Inside the function.")
    set(${outVar} 12)
    set(unrecommendedStyle 10)
    # return propagates the value to the *calling* scope
    return(PROPAGATE ${outVar} unrecommendedStyle)
endfunction()

function(oldStyleOverwrite outVar)
    # Before 3.25 you would do
    set(${outVar} "Pre 3.25" PARENT_SCOPE)
    # but this would not work from a local block
endfunction()

set(standardReturnVar 10)

message("Before function calls:")
message("  standardReturnVar = ${standardReturnVar}")
message("  unrecommendedStyle = ${unrecommendedStyle}")
message("  oldStyleReturn = ${oldStyleReturn}")

overwrite(standardReturnVar)
oldStyleOverwrite(oldStyleReturn)

# Setting new variables is a discouraged practice
message("After function calls:")
message("  standardReturnVar = ${standardReturnVar}")
message("  unrecommendedStyle = ${unrecommendedStyle}")  
message("  oldStyleReturn = ${oldStyleReturn}")
message("")
