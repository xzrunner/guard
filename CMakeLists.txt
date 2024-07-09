cmake_minimum_required(VERSION 3.8)

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

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(../logger)

add_library(guard STATIC ${ALL_FILES})
