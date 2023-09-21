#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <config.hpp>
#include <Bar.hpp>
#include <memory>
#include <mutex>
#include <Utils.hpp>

class App {
private:
  sf::Event event;
  std::vector<Bar> barBuffer;

  void parseArguments();

  void initWindow();

public:
  App();

  sf::RenderWindow *window;
  bool isRunning;

  ISorter *sorterPtr;

  void drawBuffer(ISorter *sorterPtr);

  void renderBuffer();

  // void clearBuffer();

  void pollEvent();

  // void addToBuffer(Bar &obj);

  void run(std::mutex &windowMutex);
};
