cmake_minimum_required(VERSION 3.16)

project(minimal-project VERSION 0.1 LANGUAGES CXX)

include(cmake/ProjectSettings.cmake)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Interface for c++ std and compile-time options
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Interface for warning settings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# Standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)

add_subdirectory(include)
add_subdirectory(src)
