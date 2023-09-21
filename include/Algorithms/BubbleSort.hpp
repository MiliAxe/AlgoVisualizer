#pragma once
#include <Algorithms/SortAlgorithm.hpp>

class BubbleSort : public SortAlgorithm {
public:
  BubbleSort(Sorter *sortPtr);

  void sort(App &app) override;
};
