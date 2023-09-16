#include <App.hpp>
#include <Sorter.hpp>
#include <config.hpp>

int main (int argc, char *argv[]) {
    App app = App();
    Sorter sorter;
    sorter.populate(BAR_COUNT);
    sorter.swapBar(1, 3);
    sorter.drawBars(app);
	app.run();
	return 0;
}
