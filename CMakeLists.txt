cmake_minimum_required (VERSION 3.24.2)

# For Clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the project
project(hy352-project)

# Define the library
add_library(JSONlang "")
add_subdirectory(src)
target_include_directories(JSONlang
    PRIVATE
        include             # for header files
        include/jsonlang    # to skip `jsonlang` prefix in `src` dir
)
set_target_properties(JSONlang PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/include"
)

# Add definition for the binary
add_executable(hy352-project test/main.cpp)
target_link_libraries(hy352-project JSONlang)

# Unit Tests
if(EXISTS "${PROJECT_SOURCE_DIR}/lib/Catch2")
    add_subdirectory(lib/Catch2)
    add_executable(tests test/test.cpp)
    target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
endif()
