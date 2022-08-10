message("-- Building example")

add_executable(example README.cpp)
target_link_libraries(example PRIVATE simplevectors)
