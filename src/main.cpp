#include "graphics_engine.hpp"
#include "datapoint.hpp"
#include "sorter.hpp"

#include <chrono>
#include <thread>
#include <stdexcept>

using namespace std::chrono_literals;

int main(int argc, char* argv[]) {
    size_t data_point_count;
    bool data_point_set = false;
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            std::cout << "usage: VisSort [options]" << '\n';
            std::cout << "options: " << '\n';
            std::cout << "-h, --help   Displays this menu" << '\n';
            std::cout << "-c, --count <number>   Sets data point count to number" << std::endl;
            return 0;
        } else if (arg == "-c" || arg == "--count") {
            if (argc <= i+1) {
                std::cerr << "Error: Missing number" << '\n';
                std::cout << "Usage: VisSort -c <number>" << std::endl;
                return 1;
            }
            try {
                std::string data_point_count_string = argv[(i++)+1];
                data_point_count = std::stoul(data_point_count_string);
                data_point_set = true;
                std::cout << "Data point count set successfully." << std::endl;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid Number" << std::endl;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Number is out of the valid range" << std::endl;
            }
        } else {
            std::cerr << "Invalid option" << std::endl;
            return 1;
        }
    }
    if (!data_point_set) {
        data_point_count = 200;
    }
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    int window_width = 1280;
    int window_height = 720;
    int window_pos_x = (desktop.width - window_width) / 2;
    int window_pos_y = (desktop.height - window_height) / 2;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "VisSort");
    window.setPosition(sf::Vector2i(window_pos_x, window_pos_y));
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
