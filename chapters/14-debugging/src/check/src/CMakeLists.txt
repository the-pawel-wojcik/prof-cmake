cmake_minimum_required(VERSION 3.30)
project(Check LANGUAGES)

# Functions demonstrate pass/fail behavior
function(checkSomething resultVar)
    set(${resultVar} YES PARENT_SCOPE)
endfunction()

function(checkSomethingElse resultVar)
    set(${resultVar} NO PARENT_SCOPE)
endfunction()

# Outer check starts here
message(CHECK_START "Checking things")
list(APPEND CMAKE_MESSAGE_INDENT " ")

# Inner check 1
message(CHECK_START "Checking support for something")
checkSomething(successVar1)
if(successVar1)
    message(CHECK_PASS "supported")
else()
    message(CHECK_FAIL "not supported")
endif()

# Inner check 2
message(CHECK_START "Checking support for something else")
checkSomethingElse(successVar2)
if(successVar2)
    message(CHECK_PASS "supported")
else()
    message(CHECK_FAIL "not supported")
endif()

# Outer check finishes here
list(POP_BACK CMAKE_MESSAGE_INDENT)
if(successVar1 OR successVar2)
    message(CHECK_PASS "ok")
else()
    message(CHECK_FAIL "failed")
endif()
