#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

class ISorter {
public:
  virtual void drawBars(sf::RenderWindow &window) = 0;
};

long hexStringToLong(std::string hexString);