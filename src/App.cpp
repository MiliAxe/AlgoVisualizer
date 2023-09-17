#include <App.hpp>
#include <Sorter.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <config.hpp>
#include <iostream>

void App::initWindow() {
    this->window = std::make_unique<sf::RenderWindow>(
            sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My sfml program");
}

App::App() {
    initWindow();
}

void App::pollEvent() {
    while (window->pollEvent(this->event)) {
        switch (event.type) {
            case sf::Event::KeyPressed: {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
                    sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                    window->close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                    sorterPtr->shuffleBars();
                    sorterPtr->drawBars(*this);
                }
            }
            default:
                break;
        }
    }
}

void App::drawBuffer() {
    for (const auto &obj: barBuffer) {
        window->draw(obj);
    }
}

void App::addToBuffer(Bar &obj) {
    this->barBuffer.push_back(obj);
}

void App::clearBuffer() {
    this->barBuffer.clear();
}

void App::run() {
    while (window->isOpen()) {
        pollEvent();
        window->clear();
        drawBuffer();
        window->display();
    }
}