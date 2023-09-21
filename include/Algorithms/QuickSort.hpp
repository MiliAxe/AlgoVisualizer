#pragma once
#include <Algorithms/SortAlgorithm.hpp>

class QuickSort : public SortAlgorithm
{
public:
  QuickSort(Sorter *sortPtr, std::mutex *windowMutex);

  void sort() override;

  int partition(int left, int right);

  void quickSort(int left, int right);
};
