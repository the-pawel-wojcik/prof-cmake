cmake_minimum_required(VERSION 3.30)
project(Check LANGUAGES C CXX)

include(CheckSourceCompiles)

check_source_compiles(
    C
    "int main() { int myVar; }"
    unusedNotDetected
    FAIL_REGEX "[Ww]arn"
)

if(unusedNotDetected)
    message("Unused variables do not generate warnings")
endif()

include(CheckLinkerFlag)
check_linker_flag(CXX LINKER:-stats LINKER_STATS_SUPPORTED)


if(LINKER_STATS_SUPPORTED)
    message("Linker supports the -stats flag.")
endif()

include(CheckSymbolExists)
check_symbol_exists(sprintf stdio.h HAVE_SPRINTF)


if(HAVE_SPRINTF)
    message("stdio.h includes the `sprintf` symbol.")
else()
    message("stdio.h DOES NOT include the `sprintf` symbol.")
endif()

# To detect symbols, the executable must link against the tested library
# include(CheckCXXSymbolExists)
# set(CMAKE_REQUIRED_LIBRARIES SomeCxxSDK)
# check_cxx_symbol_exists(SomeCxxInitFunc somecxxsdk.h HAVE_SOMECXXSDK)
