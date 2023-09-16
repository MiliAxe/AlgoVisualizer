#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <chrono>
#include <iostream>
#include <new>
#include <random>
#include <thread>
#include <vector>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define BAR_COUNT 800.f
void swapBars(sf::RectangleShape &rect1, sf::RectangleShape &rect2) {
  sf::Vector2f tempPos = rect1.getPosition();
  rect1.setPosition(rect2.getPosition());
  rect2.setPosition(tempPos);
  rect1.setFillColor(sf::Color::Red);
  rect2.setFillColor(sf::Color::Red);
  std::swap(rect1, rect2);
}

int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                          "My sfml program");

  std::vector<sf::RectangleShape> rects;

  for (int i = 0; i < BAR_COUNT; i++) {
    sf::Vector2f tempRectSize(WINDOW_WIDTH / BAR_COUNT,
                              (float)(i + 1) * WINDOW_HEIGHT / BAR_COUNT);
    sf::RectangleShape tempRect(tempRectSize);
    tempRect.setOrigin(0, tempRectSize.y);
    tempRect.setPosition(i * WINDOW_WIDTH / BAR_COUNT, WINDOW_HEIGHT);
    tempRect.setOutlineThickness(0.5f);
    tempRect.setOutlineColor(sf::Color::Black);
    rects.push_back(tempRect);
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
          window.close();
        }
      }
      switch (event.type) {
      case sf::Event::KeyPressed: {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
            sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
          window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
          unsigned seed =
              std::chrono::system_clock::now().time_since_epoch().count();
          std::default_random_engine generator(seed);
          std::uniform_int_distribution<int> distribution(0, BAR_COUNT - 1);
          int index1 = distribution(generator);
          int index2 = distribution(generator);

          swapBars(rects[index1], rects[index2]);
        }
      } break;

      default:

        break;
      }

      window.clear();

      for (int i = 0; i < rects.size(); i++) {
        window.draw(rects[i]);
      }

      window.display();
    }
  }
  return 0;
}
