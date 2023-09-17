#include <Bar.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <config.hpp>

sf::Vector2f Bar::calculateSize(int index) {

    sf::Vector2f tempRectSize((float) WINDOW_WIDTH / BAR_COUNT,
                              (float) (index + 1) * WINDOW_HEIGHT / BAR_COUNT);
    return tempRectSize;
}

sf::Vector2f Bar::calculatePosition(int index) {
    sf::Vector2f tempPosition((float) index * WINDOW_WIDTH / BAR_COUNT,
                              WINDOW_HEIGHT);
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
    this->setOriginToBottomLeft();
    this->setPosition(position);
}


//sf::RectangleShape Bar::getShape() const { return this->rectangle; }
