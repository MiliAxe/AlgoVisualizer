#pragma once

#include <Algorithms/SortAlgorithm.hpp>
#include <mutex>

class MergeSort : public SortAlgorithm {
public:
  MergeSort(Sorter *sorterPtr, std::mutex *windowMutex);

  void merge(int const left, int const mid, int const right);
  void mergeSort(int const begin, int const end);
  void mergeBar(int replaceIndex, int indexOfMergedArray);

  void sort() override;
};
