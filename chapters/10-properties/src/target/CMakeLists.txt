cmake_minimum_required(VERSION 3.30)
project(target_properties LANGUAGES)

get_target_property(version armadillo VERSION)

get_source_file_property(name main.cpp PROPERTIES)

if("${version}" STREQUAL "version-NOTFOUND")
    message(FATAL_ERROR "Unable to tell armadillo's version")
else()
    message("armadillo version ${version}")
endif()
