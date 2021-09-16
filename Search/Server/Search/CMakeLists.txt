project(Search)

find_package(cpprestsdk REQUIRED)

add_library(search STATIC Search.cpp)

target_link_libraries(search PRIVATE cpprestsdk::cpprest)