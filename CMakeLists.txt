cmake_minimum_required(VERSION 3.11)
project(AlgoVisualizer VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug
            CACHE STRING "Choose the type of build, options are: (Debug or Release)")
endif (NOT CMAKE_BUILD_TYPE)

# fetch latest argparse
include(FetchContent)
FetchContent_Declare(
    argparse
    GIT_REPOSITORY https://github.com/p-ranav/argparse.git
)
FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        2.6.0
)
FetchContent_MakeAvailable(sfml)
FetchContent_MakeAvailable(argparse)

#find_package(SFML 2.6
#        COMPONENTS
#        graphics
#        window
#        system
#        audio
#        REQUIRED
#)

add_executable(AlgoVisualizer)
target_sources(AlgoVisualizer PRIVATE 
        src/main.cpp 
        src/App.cpp
        src/Bar.cpp
        src/Sorter.cpp
	    src/Utils.cpp
        src/Algorithms/QuickSort.cpp
        src/Algorithms/BubbleSort.cpp
        src/Algorithms/SortAlgorithm.cpp
        src/Algorithms/MergeSort.cpp)

target_include_directories(AlgoVisualizer PRIVATE "${PROJECT_BINARY_DIR}"
        "include/"
)

target_link_libraries(AlgoVisualizer PRIVATE sfml-graphics sfml-window sfml-system sfml-audio argparse)

if ( CMAKE_COMPILER_IS_GNUCC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif()
if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif()
