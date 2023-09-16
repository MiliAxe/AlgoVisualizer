#include <Sorter.hpp>
#include <config.hpp>

void Sorter::populate(int barCount) {
    for (int i = 0; i < barCount; i++) {
        Bar tempBar(i);
        bars.push_back(tempBar);
    }
}

void Sorter::drawBars(App &app) {
    for (auto obj : bars) {
       app.addToBuffer(obj.rectangle);
    }
}

void Sorter::swapBar(int index1, int index2) {
//    sf::RectangleShape *rect1 = &bars[index1].rectangle;
//    sf::RectangleShape *rect2 = &bars[index2].rectangle;

//  sf::Vector2f tempPos = rect1.getPosition();
//  rect1.setPosition(rect2.getPosition());
//  rect2.setPosition(tempPos);
  bars[index1].rectangle.setFillColor(sf::Color::Red);
  bars[index2].rectangle.setFillColor(sf::Color::Red);
//  std::swap(bars[index1], bars[index2]);
}

Sorter::Sorter() {
    populate(BAR_COUNT);
}