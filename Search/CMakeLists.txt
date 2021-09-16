cmake_minimum_required(VERSION 3.1)
project(SearchServer)

set(CMAKE_CXX_STANDARD 17)

set(EXECUTABLE_OUTPUT_PATH "bin")
set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build/lib")

include_directories("SearchResult")
include_directories("Server")
include_directories("MySQL")

add_executable(searchServer main.cpp)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(Server)

target_link_libraries(searchServer server)
target_link_libraries(searchServer -lmysqlcppconn)
target_link_libraries(searchServer -lssl)
target_link_libraries(searchServer -lcrypto)