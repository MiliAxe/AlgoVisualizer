#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <config.hpp>
#include <thread>

class Bar : public sf::Drawable {
private:
  sf::Vector2f size;
  sf::Vector2f position;
  sf::RectangleShape rectangle;

  static sf::Vector2f calculateSize(int index);

  static sf::Vector2f calculatePosition(int index);

  void setOriginToBottomLeft();

public:
  int value;

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void setPosition(sf::Vector2f newPosition);

  void highlight(sf::Color color);

  void temporaryHighlight(sf::Color color);

  explicit Bar(int index);

  sf::RectangleShape *getShape();
};
