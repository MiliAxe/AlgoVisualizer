<div align="center">

# AlgoVisualizer

![SFML Logo](https://img.shields.io/badge/SFML-2.6.0-green?style=flat-square&logo=sfml)


Simple sorting algorithm visualizer written using SFML.

![GIF Demo](assets/demo.gif)

</div>

## Introduction

AlgoVisualizer is written with customizability in mind:
- Uses CLI arguments to change configuration
- Makes it easy to add your own sorting algorithm

## Building

### Dependencies:
- SFML

1. Clone the repository and cd into the directory:
```
git clone https://github.com/MiliAxe/AlgoVisualizer
```
2. Use CMake to generate build files:

```
cmake -S . -B build
```
3. Happy building!
```
cmake --build build
```
After building is done, the executable should be available at build directory.

## Usage
```
Usage: AlgoVisualizer [--help] [--version] [--speed VAR] [--bars VAR] [--algorithm ALGORITHM] [--resolution WIDTHxHEIGHT] [--bar-color #RRGGBBAA] [--highlight-color #RRGGBBAA] [--outline-color #RRGGBBAA] [--outline-thickness VAR]

Optional arguments:
  -h, --help                     shows help message and exits 
  -v, --version                  prints version information and exits 
  -s, --speed                    Delay between the sorting proccess, less the faster sorting is done [default: 100]
  -b, --bars                     Number of bars to sort [default: 100]
  -a, --algorithm ALGORITHM      Sorting algorithm to use [default: "MergeSort"]
  -r, --resolution WIDTHxHEIGHT  Window resolution [default: "800x600"]
  --bar-color #RRGGBBAA          Color of the bars [default: "#FFFFFFFF"]
  --highlight-color #RRGGBBAA    Color of the highlighted bars [default: "#FF0000FF"]
  --outline-color #RRGGBBAA      Color of the outline of the bars [default: "#000000FF"]
  --outline-thickness            Thickness of the outline of the bars [default: 0]
```
Currently, the following Algorithms are available:
- Bubble Sort
- Merge Sort
- Quick Sort
