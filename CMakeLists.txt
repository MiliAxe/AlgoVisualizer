cmake_minimum_required(VERSION 3.11)
project(AlgoVisualizer VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING "Choose the type of build, options are: (Debug or Release)")
endif (NOT CMAKE_BUILD_TYPE)

# configure_file(include/config.h.in config.h)

find_package(SFML 2.6
        COMPONENTS
        graphics
        window
        system
        audio
        REQUIRED
)

add_executable(AlgoVisualizer
        include/Sorter.hpp
        include/Bar.hpp
        include/App.hpp
        src/Sorter.cpp
        src/App.cpp
        src/main.cpp
        src/Bar.cpp
        include/SortAlgorithms.hpp
        src/SortAlgorithms.cpp
)
target_sources(AlgoVisualizer PRIVATE src/main.cpp src/Bar.cpp src/App.cpp)
target_include_directories(AlgoVisualizer PRIVATE "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/include"
        "include/"
)

target_link_libraries(AlgoVisualizer PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()
