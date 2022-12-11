cmake_minimum_required (VERSION 3.24.2)

# Define the project
project(hy352-project)

# Define Collections library
add_library(Collections "")
add_subdirectory(src/collections)
set_target_properties(Collections PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/src/collections"
)

# Define the library
add_library(JSONlang "")
add_subdirectory(src/jsonlang)
target_link_libraries(JSONlang Collections)
set_target_properties(JSONlang PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/src/jsonlang"
)

# Add definition for the binary
add_executable(hy352-project src/main.cpp)
target_link_libraries(hy352-project JSONlang)
