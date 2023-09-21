#include <App.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>

void App::initWindow()
{
  window = new sf::RenderWindow(
      sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My sfml program", sf::Style::Default);
  window->setVerticalSyncEnabled(true);
  window->setFramerateLimit(60);
}

App::App() { initWindow(); }

void App::pollEvent()
{
  while (window->pollEvent(this->event))
  {
    switch (event.type)
    {
    case sf::Event::KeyPressed:
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
          sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
      {
        window->close();
        this->isRunning = false;
      }
      // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
      //   sorterPtr->shuffleBars();
      //   sorterPtr->drawBars(*this);
      // }
    }
    default:
      break;
    }
  }
}

void App::drawBuffer(ISorter *sorterPtr)
{
  sorterPtr->drawBars(*window);
}

// void App::addToBuffer(Bar &obj) { this->barBuffer.push_back(obj); }

// void App::clearBuffer() { this->barBuffer.clear(); }

void App::renderBuffer()
{
  pollEvent();
  window->clear();
  drawBuffer(sorterPtr);
  window->display();
}

void App::run(std::mutex &windowMutex)
{
  while (window->isOpen())
  {
    // std::lock_guard<std::mutex> lock(windowMutex);
    renderBuffer();
  }
}
