cmake_minimum_required(VERSION 3.24)
project(DungCrawlTerm)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

include(FetchContent)

FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
)

FetchContent_MakeAvailable(SFML)

set(BUILD_SHARED_LIBS OFF)

include_directories(include)
include_directories(src)

add_executable(DungCrawlTerm
        include/Player.hpp
        src/main.cpp
        # src/ASCII_Art.cpp (Keeping this commented as per your plan)
)




target_link_libraries(DungCrawlTerm PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)


add_executable(SFMLTEST
        src/SFML_test.cpp
)

target_link_libraries(SFMLTEST PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
        SFML::Audio
)