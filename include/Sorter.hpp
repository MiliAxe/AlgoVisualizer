#ifndef SORTER_HPP
#define SORTER_HPP

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

  // void sort(SortAlgorithm &algorithm,
  //           sf::RenderWindow &window); // TODO: Add the algorithm as argument

  void drawBars(sf::RenderWindow &window) override;
  
  // void operator()();
};

#endif // SORTER_HPP
