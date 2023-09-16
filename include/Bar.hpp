#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

class Bar {
private:
  int value;
  sf::Vector2f size;
  sf::Vector2f position;
  
  static sf::Vector2f calculateSize(int index);
  static sf::Vector2f calculatePosition(int index);
  void setOriginToBottomLeft();

public:
  sf::RectangleShape rectangle;
  void setPosition(sf::Vector2f newPosition);
  sf::RectangleShape getShape() const;
  explicit Bar(int index);
};
