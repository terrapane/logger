cmake_minimum_required(VERSION 3.21)

# Define the Logger project
project(logger
        VERSION 1.0.0.0
        DESCRIPTION "Logger Library"
        LANGUAGES CXX)

# Set options depending on whether this is a subproject
if(PROJECT_IS_TOP_LEVEL)
    option(logger_BUILD_TESTS "Build Tests for the Logger Library" ON)
else()
    option(logger_BUILD_TESTS "Build Tests for the Logger Library" OFF)
endif()

# Option to control whether the LOGGER_DEBUG macros are built even for release
option(logger_DEBUG_MACROS_ALWAYS "Always build LOGGER_DEBUG macro lines" OFF)

# Option to control ability to install the library
option(logger_INSTALL "Install the Logger Library" ON)

add_subdirectory(dependencies)
add_subdirectory(src)

include(CTest)

if(BUILD_TESTING AND logger_BUILD_TESTS)
    add_subdirectory(test)
endif()
