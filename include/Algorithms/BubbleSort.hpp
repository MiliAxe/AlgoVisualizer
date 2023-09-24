#pragma once
#include <Algorithms/SortAlgorithm.hpp>
#include <mutex>

class BubbleSort : public SortAlgorithm {
public:
  BubbleSort(Sorter *sortPtr, std::mutex *windowMutex);

  void sort() override;
};
