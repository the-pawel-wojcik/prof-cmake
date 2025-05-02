cmake_minimum_required(3.11)
# Ensure non-empty default build type for single-config
get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(NOT isMultiConfig)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type")
endif()

project(Foo)

# Only modify config details if the top level project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    if(NOT isMultiConfig)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY
            STRINGS Debug Release Profile
        )
    elseif(NOT "Profile" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Profile)
    endif()
    # Set Profile-specific flag variables (see below)...
    set(CMAKE_C_FLAGS_PROFILE "-p -g -O2")
    set(CMAKE_CXX_FLAGS_PROFILE "-p -g -O2")
    set(CMAKE_EXE_LINKER_FLAGS_PROFILE "-p -g -O2")
    set(CMAKE_SHARED_LINKER_FLAGS_PROFILE "-p -g -O2")
    set(CMAKE_STATIC_LINKER_FLAGS_PROFILE "")
    set(CMAKE_MODULE_LINKER_FLAGS_PROFILE "-p -g -O2")
    # Good practice for multi-config builds
    set(CMAKE_PROFILE_POSTFIX _profile)
    # Pick one for target_link_libraries()
    set_property(GLOBAL APPEND PROPERTY
        DEBUG_CONFIGURATIONS Profile
    )
endif()
