cmake_minimum_required(VERSION 3.15)

project(cpp_hex_viewer VERSION 2.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(hexview
    src/main.cpp
    src/CLI.cpp
    src/HexViewer.cpp
    src/Formatter.cpp
    src/SignatureDB.cpp
    src/Terminal.cpp
)