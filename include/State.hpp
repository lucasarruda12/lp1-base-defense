#pragma once

#include <SFML/Graphics.hpp>

class State {
    public:
        virtual void render(sf::RenderWindow& window) = 0;
        virtual void update() = 0;
        virtual void processEvent(const sf::Event& event) = 0;
};
