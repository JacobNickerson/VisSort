#include "graphics_engine.hpp"

Graphics_Engine::Graphics_Engine(size_t size, sf::RenderWindow* win) : window(win) {
    sf::Vector2u window_size = window->getSize();
    offset = (window_size.x % size) / 2;
    const int bar_width = ((window_size.x)) / size;  
    const int bar_height_increment = (window_size.y - 200.0f) / size; 
    for (int i = 0; i < size; i++) {
        const int bar_height = bar_height_increment * (i+1);
        sf::RectangleShape rect(sf::Vector2f(bar_width-1, bar_height));  // remove 1 to account for border
        rect.setOrigin(sf::Vector2f(0, bar_height));
        rect.move(sf::Vector2f(bar_width*i+offset,window_size.y)); 
        rect.setFillColor(sf::Color(255,0,0));
        rect.setOutlineThickness(1);
        sprites.push_back(rect);
    }
}

void Graphics_Engine::drawFrame() {
    window->clear();
    for (int i = 0; i < sprites.size(); i++) {
        window->draw(sprites[i]);
    }
    window->display();
}

void Graphics_Engine::swapBars(int i, int j) {
    const sf::Vector2f i_position = sprites[i].getPosition();
    sprites[i].setPosition(sprites[j].getPosition());
    sprites[j].setPosition(i_position);
    std::swap(sprites[i], sprites[j]);
}

void Graphics_Engine::setBarColor(int i, sf::Color color) {
    sprites[i].setFillColor(color);
}

const sf::Vector2u Graphics_Engine::getWindowSize() {
    return window->getSize();
}

sf::RectangleShape* Graphics_Engine::getSprite(int i) {
    return &sprites[i];
}

const int Graphics_Engine::getOffset() {
    return offset;
}