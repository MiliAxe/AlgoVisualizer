#include <Algorithms/BubbleSort.hpp>
#include <thread>

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
