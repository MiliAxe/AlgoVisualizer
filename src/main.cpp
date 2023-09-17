#include <App.hpp>
#include <Sorter.hpp>
#include <SortAlgorithms.hpp>
#include <thread>

// TODO: Add one render only method

int main(int argc, char *argv[])
{
    App app = App();
    app.isRunning = true;
    Sorter sorter;
    app.sorterPtr = &sorter;
    sorter.shuffleBars();
    sorter.drawBars(app);

    QuickSort sortAlgo(&sorter);
    sortAlgo.sort(app);

    app.run();

    return 0;
}
