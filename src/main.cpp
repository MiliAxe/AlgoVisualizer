#include <Algorithms/QuickSort.hpp>
#include <App.hpp>
#include <Sorter.hpp>
#include <mutex>
#include <thread>

int main(int argc, char *argv[]) {
  Sorter sorter;
  sorter.shuffleBars();

  std::mutex windowMutex;

  std::thread sortThread([&]() {
    QuickSort sortAlgo(&sorter, &windowMutex);
    sortAlgo.sort();
  });

  std::thread renderingThread([&]() {
    App app = App();
    app.sorterPtr = &sorter;
    app.isRunning = true;
    app.run(windowMutex);
  });

  renderingThread.join();
  sortThread.join();
  return 0;
}
