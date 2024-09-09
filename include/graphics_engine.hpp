#ifndef GRAPHICS_ENGINE_HPP
#define GRAPHICS_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Graphics_Engine {
    public:
        Graphics_Engine(size_t size, sf::RenderWindow* win);

        void drawFrame();

        void swapBars(int i, int j);

        void setBarColor(int i, sf::Color color);

        void updateBar(int i);

        void updateAllBars();

        const sf::Vector2u getWindowSize();

        sf::RectangleShape* getSprite(int i);

    private:
        std::vector<sf::RectangleShape> sprites;
        sf::Vector2u window_size;
        sf::RenderWindow* window;
};

#endif