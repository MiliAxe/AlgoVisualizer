#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

class App {
private:
  sf::Event event;
  std::vector<sf::RectangleShape> rectBuffer;

  void parseArguments();
  void initWindow();
  void drawBuffer();

public:
  std::unique_ptr<sf::RenderWindow> window;
  App();
  void pollEvent();
  void addToBuffer(sf::RectangleShape &obj);
  void run();
};
