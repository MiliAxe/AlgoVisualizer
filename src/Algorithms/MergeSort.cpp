#include "Sorter.hpp"
#include "config.hpp"
#include <Algorithms/MergeSort.hpp>
#include <mutex>

MergeSort::MergeSort(Sorter *sorterPtr, std::mutex *windowMutex) {
  this->sorterPtr = sorterPtr;
  this->windowMutex = windowMutex;
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void MergeSort::merge(int const left, int const mid, int const right) {
  int const subArrayOne = mid - left + 1;
  int const subArrayTwo = right - mid;

  // Create temp arrays
  auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

  // Copy data to temp arrays leftArray[] and rightArray[]
  for (auto i = 0; i < subArrayOne; i++) {
    std::lock_guard<std::mutex> lock(*windowMutex);
    leftArray[i] = sorterPtr->bars[left + i].value;
  }
  for (auto j = 0; j < subArrayTwo; j++) {
    std::lock_guard<std::mutex> lock(*windowMutex);
    rightArray[j] = sorterPtr->bars[mid + 1 + j].value;
  }

  auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
  int indexOfMergedArray = left;

  // Merge the temp arrays back into array[left..right]
  while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
    if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
      // sorterPtr->copyBarToEnd(indexOfMergedArray);
      // sorterPtr->bars[indexOfMergedArray].highlight(
      //     config::BAR_HIGHLIGHT_COLOR);
      // sorterPtr->replaceBar(leftArray[indexOfSubArrayOne],
      // indexOfMergedArray); std::this_thread::sleep_for(
      //     std::chrono::milliseconds(config::SORT_DELAY));
      // sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_COLOR);
      mergeBar(leftArray[indexOfSubArrayOne], indexOfMergedArray);
      indexOfSubArrayOne++;
    } else {
      // sorterPtr->copyBarToEnd(indexOfMergedArray);
      // sorterPtr->replaceBar(rightArray[indexOfSubArrayTwo],
      // indexOfMergedArray); sorterPtr->bars[indexOfMergedArray].highlight(
      //     config::BAR_HIGHLIGHT_COLOR);
      // std::this_thread::sleep_for(
      //     std::chrono::milliseconds(config::SORT_DELAY));
      // sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_COLOR);
      mergeBar(rightArray[indexOfSubArrayTwo], indexOfMergedArray);
      indexOfSubArrayTwo++;
    }
    // sorterPtr->clearBarCache();
    indexOfMergedArray++;
  }

  // Copy the remaining elements of
  // left[], if there are any
  while (indexOfSubArrayOne < subArrayOne) {
    // sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_COLOR);
    // std::this_thread::sleep_for(std::chrono::milliseconds(config::SORT_DELAY));
    // sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_HIGHLIGHT_COLOR);
    // sorterPtr->copyBarToEnd(indexOfMergedArray);
    // sorterPtr->replaceBar(leftArray[indexOfSubArrayOne], indexOfMergedArray);
    mergeBar(leftArray[indexOfSubArrayOne], indexOfMergedArray);
    indexOfSubArrayOne++;
    indexOfMergedArray++;
  }

  // Copy the remaining elements of
  // right[], if there are any
  while (indexOfSubArrayTwo < subArrayTwo) {
    // sorterPtr->copyBarToEnd(indexOfMergedArray);
    // sorterPtr->replaceBar(rightArray[indexOfSubArrayTwo],
    // indexOfMergedArray);
    // sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_HIGHLIGHT_COLOR);
    // std::this_thread::sleep_for(std::chrono::milliseconds(config::SORT_DELAY));
    // sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_COLOR);
    mergeBar(rightArray[indexOfSubArrayTwo], indexOfMergedArray);
    indexOfSubArrayTwo++;
    indexOfMergedArray++;
  }
  delete[] leftArray;
  delete[] rightArray;
}

void MergeSort::mergeSort(int const begin, int const end) {
  if (begin >= end)
    return;

  int mid = begin + (end - begin) / 2;
  mergeSort(begin, mid);
  mergeSort(mid + 1, end);
  merge(begin, mid, end);
}

void MergeSort::sort() { mergeSort(0, sorterPtr->bars.size() - 1); }

void MergeSort::mergeBar(int replaceIndex, int indexOfMergedArray) {
  windowMutex->lock();
  sorterPtr->replaceBar(replaceIndex, indexOfMergedArray);
  sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_HIGHLIGHT_COLOR);
  windowMutex->unlock();

  std::this_thread::sleep_for(std::chrono::milliseconds(config::SORT_DELAY));

  windowMutex->lock();
  sorterPtr->bars[indexOfMergedArray].highlight(config::BAR_COLOR);
  sorterPtr->copyBarToEnd(indexOfMergedArray);
  windowMutex->unlock();

  sorterPtr->clearBarCache();
}
