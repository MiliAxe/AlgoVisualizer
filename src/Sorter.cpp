#include <Sorter.hpp>
#include <config.hpp>
#include <Windows.h>

void Sorter::populate(int barCount) {
    for (int i = 0; i < barCount; i++) {
        Bar tempBar(i);
        bars.push_back(tempBar);
    }
}

void Sorter::drawBars(App &app) {
    app.clearBuffer();
    for (auto obj: bars) {
        app.addToBuffer(obj);
    }
}

void Sorter::swapBar(int index1, int index2) {
    sf::RectangleShape *rect1 = &bars[index1].rectangle;
    sf::RectangleShape *rect2 = &bars[index2].rectangle;


    sf::Vector2f tempPos = rect1->getPosition();
    rect1->setPosition(rect2->getPosition());
    rect2->setPosition(tempPos);
    std::swap(bars[index1], bars[index2]);
}

Sorter::Sorter() {
    populate(BAR_COUNT);
}

void Sorter::shuffleBars() {
    auto seed = (unsigned int) std::chrono::system_clock::now().time_since_epoch().count();
    auto randomEngine = std::default_random_engine{seed};
    std::uniform_int_distribution<int> intDistribution(0, (int) bars.size() - 1);

    for (int i = 0; i < BAR_COUNT * 2; ++i) {
        swapBar(intDistribution(randomEngine), intDistribution(randomEngine));
    }
}