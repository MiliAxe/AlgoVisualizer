#pragma once

#include <App.hpp>
#include <Bar.hpp>
#include <SFML/Window/Window.hpp>
#include <vector>

class Sorter {
private:
  std::vector<Bar> bars;
  static void shuffleBars(std::vector<Bar> &bars);

public:
  Sorter();
  void populate(int barCount);
  void swapBar(int index1, int index2);
  void sort(); // TODO: Add the algorithm as argument
  void drawBars(App &app);
};
