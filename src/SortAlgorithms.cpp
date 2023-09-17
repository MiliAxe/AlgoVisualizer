#include <SortAlgorithms.hpp>
#include <Windows.h>

BubbleSort::BubbleSort(Sorter *sortPtr) {
    this->sorterPtr = sortPtr;
}

void BubbleSort::sort(App &app) {
    int i, j;
    int n = static_cast<int>(sorterPtr->bars.size());
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            sorterPtr->bars[j].rectangle.setFillColor(sf::Color::Red);
            if (sorterPtr->bars[j].value > sorterPtr->bars[j + 1].value) {
//                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                sorterPtr->swapBar
                        (j, j + 1);
                swapped = true;
            }
            app.pollEvent();
            app.window->clear();
            sorterPtr->drawBars(app);
            app.drawBuffer();
            app.window->display();
            sorterPtr->bars[j].rectangle.setFillColor(sf::Color::White);
        }
        sorterPtr->bars[j].rectangle.setFillColor(sf::Color::White);



        // If no two elements were swapped
        // by inner loop, then break
        if (!swapped) {
            break;
        }
    }
}