
cmake_minimum_required(VERSION 3.9)
project(ControlWebcamOpenCV)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} -W -Wall -Wextra -Wundef -Wpointer-arith -Wcast-align -Wcast-qual -Wunreachable-code -I /usr/include -L /usr/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs")

set(SOURCE_FILES
        src/source/Main.cpp)

add_executable(webcam_controller ${SOURCE_FILES})
