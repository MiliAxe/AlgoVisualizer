#pragma once

#include <Bar.hpp>
#include <App.hpp>

#include <SFML/Window/Window.hpp>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

//class App;

class Sorter {
public:
    std::vector<Bar> bars;

    Sorter();

    void shuffleBars();

    void populate(int barCount);

    void swapBar(int index1, int index2);

    void sort(); // TODO: Add the algorithm as argument

    void drawBars(App &app);
};
