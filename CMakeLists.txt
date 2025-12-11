cmake_minimum_required(VERSION 3.16)

project(guard)

################################################################################
# Source groups
################################################################################
set(Headers
    "include/guard/check.h"
    "include/guard/config.h"
    "include/guard/Diagnostic.h"
    "include/guard/Exception.h"
)
source_group("Headers" FILES ${Headers})

set(Sources
    "source/Diagnostic.cpp"
    "source/Exception.cpp"
)
source_group("Sources" FILES ${Sources})

set(ALL_FILES
    ${Headers}
    ${Sources}
)

add_library(${PROJECT_NAME} STATIC ${ALL_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include external/logger)
