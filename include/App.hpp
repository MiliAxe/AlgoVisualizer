#pragma once

//#include <Sorter.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

class Sorter;

class Bar;

class App {
private:
    sf::Event event;
    std::vector<Bar> barBuffer;

    void parseArguments();

    void initWindow();


public:
    bool isRunning;
    
    std::unique_ptr<sf::RenderWindow> window;

    Sorter *sorterPtr;

    void drawBuffer();

    void renderBuffer();

    App();

    void clearBuffer();

    void pollEvent();

    void addToBuffer(Bar &obj);

    void run();
};
