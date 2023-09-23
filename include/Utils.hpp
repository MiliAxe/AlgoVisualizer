#ifndef UTILS_HPP
#define UTILS_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class ISorter {
public:
  virtual void drawBars(sf::RenderWindow &window) = 0;
};

long hexStringToLong(std::string hexString);

#endif // UTILS_HPP
