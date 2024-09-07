#include "graphics_engine.hpp"
#include "datapoint.hpp"
#include "sorter.hpp"

#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "VisSort");
    size_t data_point_count = 200;
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
                switch (event.key.code) {
                    case sf::Keyboard::Escape: 
                        sorter.shuffleData();
                        break;

                    case sf::Keyboard::I: 
                        sorter.insertionSort();
                        sorter.verifySortGraphically();
                        break;
                    
                    case sf::Keyboard::B:
                        sorter.bogoSort();
                        sorter.verifySortGraphically();
                        break;

                    case sf::Keyboard::Q:
                        sorter.quickSort(0, data_point_count-1);
                        sorter.verifySortGraphically();
                        break;

                    case sf::Keyboard::M:
                        sorter.mergeSort(0,data_point_count-1);
                        sorter.verifySortGraphically();
                        break;

                    case sf::Keyboard::S:
                        sorter.selectionSort();
                        sorter.verifySortGraphically();
                        break;
                    
                    case sf::Keyboard::U:
                        sorter.bubbleSort();
                        sorter.verifySortGraphically();
                        break;

                    case sf::Keyboard::V:
                        sorter.verifySortGraphically();
                        break;
                }
            }
        }

        graphics.drawFrame();
    }

    return 0;
}