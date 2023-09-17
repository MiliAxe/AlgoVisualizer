#include <SortAlgorithms.hpp>
#include <thread>
#include <config.hpp>

void resetHighlight(Bar& bar) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    bar.highlight(BAR_COLOR); // Assuming sf::Color::White represents white color
}

BubbleSort::BubbleSort(Sorter *sortPtr) { this->sorterPtr = sortPtr; }

void BubbleSort::sort(App &app) {

  int i, j;
  int n = static_cast<int>(sorterPtr->bars.size());

  bool swapped;
  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1 && app.isRunning == true; j++) {

      if (sorterPtr->bars[j].value > sorterPtr->bars[j + 1].value) {
        sorterPtr->swapBar(j, j + 1);
        swapped = true;
      }

      sorterPtr->bars[j].highlight(sf::Color::Red);
      sorterPtr->bars[j + 1].highlight(sf::Color::Red);
      sorterPtr->drawBars(app);
      app.renderBuffer();
      sorterPtr->bars[j].highlight(sf::Color::White);
      sorterPtr->bars[j + 1].highlight(sf::Color::White);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    if (!swapped) {
      break;
    }
  }
}

QuickSort::QuickSort(Sorter *sortPtr) { this->sorterPtr = sortPtr; }

int QuickSort::partition(std::vector<Bar> &bars, int left, int right,
                         App &app) {
  int pivotIndex = left + (right - left) / 2;
  int pivotValue = bars[pivotIndex].value;
  int i = left, j = right;
  while (i <= j) {
    while (bars[i].value < pivotValue) {
      i++;
    }
    while (bars[j].value > pivotValue) {
      j--;
    }
    if (i <= j) {
      sorterPtr->bars[i].highlight(BAR_HIGHLIGHT_COLOR);
      sorterPtr->bars[j].highlight(BAR_HIGHLIGHT_COLOR);
      sorterPtr->swapBar(j, i);
      sorterPtr->drawBars(app);

      app.renderBuffer();
      std::this_thread::sleep_for(std::chrono::milliseconds(SORT_DELAY));
      std::thread resetThreadi(resetHighlight, std::ref(sorterPtr->bars[i]));
      resetThreadi.detach();
      std::thread resetThreadj(resetHighlight, std::ref(sorterPtr->bars[j]));
      resetThreadj.detach();
      i++;
      j--;
    }
  }
  return i;
}

void QuickSort::quickSort(std::vector<Bar> &values, int left, int right,
                          App &app) {
  if (left < right) {
    int pivotIndex = partition(values, left, right, app);
    quickSort(values, left, pivotIndex - 1, app);
    quickSort(values, pivotIndex, right, app);
  }
}

void QuickSort::sort(App &app) {
  quickSort(sorterPtr->bars, 0, sorterPtr->bars.size() - 1, app);
  sorterPtr->checkIfSortedAnimation(app);
}
