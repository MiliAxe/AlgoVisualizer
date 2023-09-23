#include <Bar.hpp>

sf::Vector2f Bar::calculateSize(int index) {

    sf::Vector2f tempRectSize((float) config::WINDOW_WIDTH / config::BAR_COUNT,
                              (float) (index + 1) * config::WINDOW_HEIGHT / config::BAR_COUNT);
    return tempRectSize;
}

sf::Vector2f Bar::calculatePosition(int index) {
    sf::Vector2f tempPosition((float) index * config::WINDOW_WIDTH / config::BAR_COUNT,
                              config::WINDOW_HEIGHT);
    return tempPosition;
}

void Bar::setOriginToBottomLeft() {
    this->rectangle.setOrigin(0, this->size.y);
}

void Bar::setPosition(sf::Vector2f newPosition) {
    this->rectangle.setPosition(newPosition);
}

void Bar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->rectangle, states);
}

Bar::Bar(int index) : value(index) {
    position = Bar::calculatePosition(index);
    size = Bar::calculateSize(index);

    this->rectangle = sf::RectangleShape(size);
    this->rectangle.setFillColor(config::BAR_COLOR);
    this->rectangle.setOutlineColor(config::BAR_OUTLINE_COLOR);
    this->rectangle.setOutlineThickness(config::BAR_OUTLINE_THICKNESS);
    this->setOriginToBottomLeft();
    this->setPosition(position);
}

void Bar::highlight(sf::Color color) {
    this->rectangle.setFillColor(color);
}

void Bar::temporaryHighlight(sf::Color color) {
    this->highlight(color);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    this->highlight(color);
}

sf::RectangleShape* Bar::getShape()  { return &this->rectangle; }
