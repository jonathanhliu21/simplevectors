message("-- Building example")

add_executable(example README_examples.cpp)
target_link_libraries(example PRIVATE simplevectors)
