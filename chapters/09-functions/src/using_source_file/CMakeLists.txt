cmake_minimum_required(VERSION 3.30)

function(writeSomeFile toWhere)
  configure_file(${CMAKE_CURRENT_FUNCTION_LIST_DIR}/template.cpp.in ${toWhere}
                 @ONLY)
endfunction()

add_subdirectory("./subdir/")
