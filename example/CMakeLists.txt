message("-- Building example")

add_executable(example 
    README_examples.cpp
    2d_3d_examples.cpp
    4d_vector.cpp)
target_link_libraries(example PRIVATE simplevectors)
