#include <Algorithms/QuickSort.hpp>
// #include <Algorithms/SortAlgorithm.hpp>
#include <config.hpp>
#include <thread>

QuickSort::QuickSort(Sorter *sortPtr,std::mutex *windowMutex)
{
  this->sorterPtr = sortPtr;
  this->windowMutex = windowMutex;
}


int QuickSort::partition(int left, int right)
{
  int pivotIndex = left + (right - left) / 2;
  int pivotValue = sorterPtr->bars[pivotIndex].value;
  int i = left, j = right;
  while (i <= j)
  {
    while (sorterPtr->bars[i].value < pivotValue)
    {
      i++;
    }
    while (sorterPtr->bars[j].value > pivotValue)
    {
      j--;
    }
    if (i <= j)
    {
      sorterPtr->bars[i].highlight(BAR_HIGHLIGHT_COLOR);
      sorterPtr->bars[j].highlight(BAR_HIGHLIGHT_COLOR);
      sorterPtr->swapBar(j, i);

      std::this_thread::sleep_for(std::chrono::milliseconds(SORT_DELAY));

      sorterPtr->bars[i].highlight(BAR_COLOR);
      sorterPtr->bars[j].highlight(BAR_COLOR);
      i++;
      j--;
    }
  }
  return i;
}

void QuickSort::quickSort(int left, int right)
{
  if (left < right)
  {
    int pivotIndex = partition(left, right);
    quickSort(left, pivotIndex - 1);
    quickSort(pivotIndex, right);
  }
}

void QuickSort::sort()
{
  quickSort(0, sorterPtr->bars.size() - 1);
  sorterPtr->checkIfSortedAnimation();
}
