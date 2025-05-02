cmake_minimum_required(3.11)
project(Foo)

# Only make changes if we are the top level project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    get_property(isMultiConfig GLOBAL
        PROPERTY GENERATOR_IS_MULTI_CONFIG
    )
    if(isMultiConfig)
        if(NOT "Profile" IN_LIST CMAKE_CONFIGURATION_TYPES)
            list(APPEND CMAKE_CONFIGURATION_TYPES Profile)
        endif()
    endif()
    # Set Profile-specific flag variables as needed...
endif()
