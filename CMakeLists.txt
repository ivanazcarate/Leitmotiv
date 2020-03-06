cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS net core base gl)


include(${wxWidgets_USE_FILE})

add_executable(main src/main.cpp
                    src/Idea.cpp
                    src/Motiv.cpp
                    src/Player.cpp)

target_link_libraries(main ${wxWidgets_LIBRARIES})
target_link_libraries(main sfml-graphics sfml-audio)