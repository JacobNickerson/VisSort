#include "graphics_engine.hpp"
#include "datapoint.hpp"
#include "sorter.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "VisSort");
    size_t data_point_count = 50;
    Graphics_Engine graphics(data_point_count, &window);
    Sorter sorter(data_point_count, &graphics);
    sorter.shuffleData();
    sorter.updateGraphics();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::S) {
                    sorter.shuffleData();
                } else if (event.key.code == sf::Keyboard::I) {
                    sorter.insertionSort();
                    sorter.verifySortGraphically();
                } else if (event.key.code == sf::Keyboard::B) {
                    sorter.bogoSort();
                    sorter.verifySortGraphically();
                } else if (event.key.code == sf::Keyboard::Q) {
                    sorter.quickSort(0, data_point_count-1);
                    sorter.verifySortGraphically();
                } else if (event.key.code == sf::Keyboard::M) {
                    sorter.mergeSort(0,data_point_count-1);
                    sorter.verifySortGraphically();
                }
            }
        }

        graphics.drawFrame();
    }
    return 0;
}