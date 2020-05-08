cmake_minimum_required(VERSION 3.16)

project(clang-tidy-project VERSION 0.1 LANGUAGES CXX)

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

# Allow static analysis options
include(cmake/StaticAnalyzers.cmake)

option(BUILD_SHARED_LIBS "Enable compilation of shared libraries" OFF)
option(ENABLE_TESTING "Enable test builds" ON)

# Run conan
include (cmake/Conan.cmake)
run_conan()

if (ENABLE_TESTING)
  enable_testing()
  message("Building tests.")
  add_subdirectory(test)
endif()

add_subdirectory(include)
add_subdirectory(src)
