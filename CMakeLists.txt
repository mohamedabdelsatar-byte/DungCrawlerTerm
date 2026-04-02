cmake_minimum_required(VERSION 4.1)
project(DungCrawlTerm)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(DungCrawlTerm
        include/ASCII_Art.hpp
        include/Player.hpp
        src/ASCII_Art.cpp
        src/main.cpp
        #src/testerASCII.cpp
)

add_executable(ArtTester #for testing
        #src/testerASCII.cpp
        src/ASCII_Art.cpp
)