#pragma once

#include <App.hpp>
#include <Sorter.hpp>
#include <vector>
#include <mutex>

class SortAlgorithm
{
protected:
  Sorter *sorterPtr;
  // std::mutex *windowMutex;
  static void resetHighlight(Bar &bar);

public:
  virtual void sort() = 0;
};
