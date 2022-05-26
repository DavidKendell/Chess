cmake_minimum_required(VERSION 3.22)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess
        Arbiter.cpp
        Arbiter.h
        Board.cpp
        Board.h
        Piece.cpp
        Piece.h
        Player.cpp
        Player.h
        Source.cpp)
