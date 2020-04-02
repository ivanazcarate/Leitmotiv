cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(wxWidgets REQUIRED COMPONENTS net core base gl)


include(${wxWidgets_USE_FILE})

add_executable(bin  src/app/App.cpp
                    src/widgets/MainFrame.cpp
                    src/widgets/AudioPlayerPanel.cpp
                    src/widgets/IdeasPanel.cpp
                    src/Idea.cpp
                    src/Motiv.cpp
                    src/Player.cpp
                    src/Character.cpp)

include_directories(src/
                    src/widgets/)

target_link_libraries(bin ${wxWidgets_LIBRARIES} sfml-graphics sfml-audio)