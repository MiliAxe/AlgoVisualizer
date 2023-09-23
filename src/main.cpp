#include <Algorithms/BubbleSort.hpp>
#include <Algorithms/QuickSort.hpp>
#include <argparse/argparse.hpp>
#include <config.hpp>
#include <thread>

argparse::ArgumentParser argParser("AlgoVisualizer");
SortAlgorithm *selectedAlgorithm;
Sorter sorter;

namespace config {
sf::Color BAR_COLOR;
sf::Color BAR_HIGHLIGHT_COLOR;
sf::Color BAR_OUTLINE_COLOR;
int BAR_OUTLINE_THICKNESS;

int WINDOW_HEIGHT;
int WINDOW_WIDTH;
int BAR_COUNT;
int SORT_DELAY;
} // namespace config

SortAlgorithm *getSortAlgorithm(std::string algorithmName, Sorter *sorterPtr) {
  if (algorithmName == "QuickSort") {
    return new QuickSort(sorterPtr);
  }
  if (algorithmName == "BubbleSort") {
    return new BubbleSort(sorterPtr);
  }

  else {
    std::cerr << "Invalid algorithm name" << std::endl;
    std::exit(1);
  }
}

void initParser() {
  argParser.add_argument("-s", "--speed")
      .help(
          "Delay between the sorting proccess, less the faster sorting is done")
      .default_value(100)
      .scan<'d', int>();
  argParser.add_argument("-b", "--bars")
      .help("Number of bars to sort")
      .default_value(100)
      .scan<'d', int>();
  argParser.add_argument("-r", "--resolution")
      .help("Window resolution")
      .default_value("800x600")
      .metavar("WIDTHxHEIGHT");
  argParser.add_argument("--bar-color")
      .help("Color of the bars")
      .default_value("#FFFFFFFF")
      .metavar("#RRGGBBAA");
  argParser.add_argument("--highlight-color")
      .help("Color of the highlighted bars")
      .default_value("#FF0000FF")
      .metavar("#RRGGBBAA");
  argParser.add_argument("--outline-color")
      .help("Color of the outline of the bars")
      .default_value("#000000FF")
      .metavar("#RRGGBBAA");
  argParser.add_argument("--outline-thickness")
      .help("Thickness of the outline of the bars")
      .default_value(0)
      .scan<'d', int>();
  argParser.add_argument("-a", "--algorithm")
      .help("Sorting algorithm to use")
      .default_value("QuickSort")
      .metavar("ALGORITHM");
}

void parseArgs(int argc, char *argv[]) {
  try {
    argParser.parse_args(argc, argv);
  } catch (const std::runtime_error &err) {
    std::cerr << err.what() << std::endl;
    std::cerr << argParser;
    std::exit(1);
  }

  config::SORT_DELAY = argParser.get<int>("--speed");
  config::BAR_COUNT = argParser.get<int>("--bars");
  config::BAR_OUTLINE_THICKNESS = argParser.get<int>("--outline-thickness");

  // Resolution format: 800x600
  auto resolutionString = argParser.get<std::string>("--resolution");
  if (resolutionString.find("x") == std::string::npos) {
    std::cerr << "Invalid resolution format" << std::endl;
    std::exit(1);
  }
  config::WINDOW_WIDTH =
      std::stoi(resolutionString.substr(0, resolutionString.find("x")));
  config::WINDOW_HEIGHT = std::stoi(resolutionString.substr(
      resolutionString.find("x") + 1, resolutionString.size()));
  config::BAR_COLOR =
      sf::Color(hexStringToLong(argParser.get<std::string>("--bar-color")));
  config::BAR_HIGHLIGHT_COLOR = sf::Color(
      hexStringToLong(argParser.get<std::string>("--highlight-color")));
  config::BAR_OUTLINE_COLOR =
      sf::Color(hexStringToLong(argParser.get<std::string>("--outline-color")));

  sorter = Sorter();

  selectedAlgorithm =
      getSortAlgorithm(argParser.get<std::string>("-a"), &sorter);
}

int main(int argc, char *argv[]) {
  initParser();
  parseArgs(argc, argv);

  std::thread sortThread([&]() {
    sorter.shuffleBars();
    selectedAlgorithm->sort();
  });

  std::thread renderingThread([&]() {
    App app = App();
    app.sorterPtr = &sorter;
    app.isRunning = true;
    app.run();
  });

  renderingThread.join();
  sortThread.join();
  return 0;
}
