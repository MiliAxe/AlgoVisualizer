#include <App.hpp>
#include <Sorter.hpp>
#include <SortAlgorithms.hpp>
#include <thread>

// TODO: Add one render only method

int main(int argc, char *argv[]) {
    App app = App();
    Sorter sorter;
    app.sorterPtr = &sorter;
    sorter.shuffleBars();
    BubbleSort sortAlgo(&sorter);
    sortAlgo.sort(app);
    app.run();
    return 0;
}