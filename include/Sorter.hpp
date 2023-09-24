#pragma once

#include <Bar.hpp>
#include <chrono>
#include <random>
#include <Utils.hpp>

class Sorter : public ISorter {
public:
  std::vector<Bar> bars;

  Sorter();

  void shuffleBars();

  void populate(int barCount);

  void swapBar(int index1, int index2);

  void checkIfSortedAnimation();

  void drawBars(sf::RenderWindow &window) override;
  
  // Useful for Algorithms that don't use swapBar and directly replace the value
  void replaceBar(int value, int index);
  void copyBarToEnd(int index);
  // The rest of the bars can be used as a cache until the end of the sorting proccess
  void clearBarCache();
  
};