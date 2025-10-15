project(pc-app)
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)

add_executable(pc-app src/main.cpp src/utils/helpers.cpp)

# Add any required libraries here
# target_link_libraries(pc-app <library_name>)