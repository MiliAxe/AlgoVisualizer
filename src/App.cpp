#include <App.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <config.hpp>
#include <iostream>

void App::initWindow() {
  this->window = std::make_unique<sf::RenderWindow>(
      sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My sfml program");
}

App::App(){ initWindow();
}

void App::pollEvent() {
  while (window->pollEvent(this->event)) {
    switch (event.type) {
    case sf::Event::KeyPressed: {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
          sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
        window->close();
      }
    }
    default:
      break;
    }
  }
}

void App::drawBuffer() {
    for (auto obj : rectBuffer) {
        window->draw(obj);
    }
}

void App::addToBuffer(sf::RectangleShape &obj) {
    this->rectBuffer.push_back(obj);
}


void App::run() {
  while (window->isOpen()) {
    pollEvent();
    window->clear();
    drawBuffer();
    window->display();
  }
}
