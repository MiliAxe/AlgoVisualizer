#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class Bar : public sf::Drawable {
private:
    sf::Vector2f size;
    sf::Vector2f position;

    static sf::Vector2f calculateSize(int index);

    static sf::Vector2f calculatePosition(int index);

    void setOriginToBottomLeft();


public:
    int value;
    sf::RectangleShape rectangle;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setPosition(sf::Vector2f newPosition);

//    sf::RectangleShape getShape() const;

    explicit Bar(int index);
};
