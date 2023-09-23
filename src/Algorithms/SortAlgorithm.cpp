#include <Algorithms/SortAlgorithm.hpp>
#include <config.hpp> 
#include <thread>

void SortAlgorithm::resetHighlight(Bar &bar) {
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  bar.highlight(config::BAR_COLOR);
}
