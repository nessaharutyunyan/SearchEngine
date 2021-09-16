project(Server)

include_directories("Search")
include_directories("../MySQL")

add_subdirectory(Search)

add_library(server STATIC Server.cpp)

target_link_libraries(server search)