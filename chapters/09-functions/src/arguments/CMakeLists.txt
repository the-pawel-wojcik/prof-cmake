cmake_minimum_required(VERSION 3.30)

message("\n  Inside the arguments subdir:")

function(perfect_forwarding)
  cmake_parse_arguments(PARSE_ARGV 0 fwd "" "" "")
  howmanyargs(${fwd_UNPARSED_ARGUMENTS})
endfunction()

function(howManyArgs)
  message("  ARGC=${ARGC}. ARGN='${ARGN}'")
endfunction()

set(spaces "alpha        beta")
set(semicolons "alpha;;;;;;beta;gamma")
set(empty "")
set(space " ")
set(semicolon ";")
set(semiSpace "; ")
set(spaceSemi " ;")
set(spaceSemiSpace " ; ")
set(spaceSemiSemi " ;;")
set(semiSemiSpace ";; ")
set(spaceSemiSemiSpace " ;; ")

foreach(
  var
  "${spaces}"
  "${semicolons}"
  "${empty}"
  "${space}"
  "${semicolon}"
  "${semiSpace}"
  "${spaceSemi}"
  "${spaceSemiSpace}"
  "${spaceSemiSemi}"
  "${semiSemiSpace}"
  "${spaceSemiSemiSpace}"
  "     ;;;;;")
  message("var='${var}'")
  howmanyargs(${var})
  perfect_forwarding(${var})
  message("")
endforeach()
