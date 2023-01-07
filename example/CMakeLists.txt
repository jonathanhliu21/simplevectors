message("-- Building example")

add_executable(example 
    basic_examples.cpp
    2d_3d_examples.cpp
    4d_vector.cpp
    complex_example.cpp
    em_example.cpp
    kinematics_example.cpp)
target_link_libraries(example PRIVATE simplevectors)
