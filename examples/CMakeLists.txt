cmake_minimum_required(VERSION 3.10)

# state_example
add_executable(state_example state_example.cpp)
target_link_libraries(state_example libst)

# readme_example
add_executable(readme_example readme_example.cpp)
target_link_libraries(readme_example libst)