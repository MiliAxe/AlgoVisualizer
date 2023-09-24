#pragma once

#include <SFML/Graphics.hpp>
#include <Bar.hpp>
#include <Utils.hpp>
#include <mutex>

class App
{
private:
  sf::Event event;
  std::vector<Bar> barBuffer;

  void parseArguments();

  void initWindow();

public:
  App();

  sf::RenderWindow *window;
  std::mutex *windowMutex;
  bool isRunning;

  ISorter *sorterPtr;

  void drawBuffer(ISorter *sorterPtr);

  void renderBuffer();

  void pollEvent();

  void run();
};