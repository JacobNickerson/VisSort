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
    int window_width;
    bool window_width_set = false;
    int window_height;
    bool window_height_set = false;
    const sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-h" || arg == "--help") {
            std::cout << "usage: vis-sort [options]" << '\n';
            std::cout << "options: " << '\n';
            std::cout << "-h, --help             Displays this menu" << '\n';
            std::cout << "-c, --count <number>   Sets data point count to number" << '\n';
            std::cout << "-H, --height           Sets the window height, width is automatically set if not specified with -W" << '\n';
            std::cout << "-W, --width            Sets the window width, height is automatically set if not specified with -H" << '\n';
            return 0;
        } else if (arg == "-c" || arg == "--count") {
            if (data_point_set) {
                std::cerr << "Error: Data point count already set" << std::endl;
                return 1;
            }
            if (argc <= i+1) {
                std::cerr << "Error: Missing number" << '\n';
                std::cout << "Usage: vis-sort -c <number>" << std::endl;
                return 1;
            }

            try {
                std::string data_point_count_string = argv[(i++)+1];
                data_point_count = std::stoul(data_point_count_string);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid Number" << std::endl;
                return 1;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Number is out of the valid range" << std::endl;
                return 1;
            }

            if (data_point_count <= 0) { 
                std::cerr << "Error: Data point count must be greater than 0" << std::endl;
                return 1;
            } else {
                data_point_set = true;
            }
        } else if (arg == "-W" || arg == "--width") {
            if (window_width_set) {
                std::cerr << "Error: Window width already set" << std::endl;
                return 1;
            } 
            if (argc <= i+1) {
                std::cerr << "Error: Missing screen width" << '\n';
                std::cout << "Usage: vis-sort -w <width>" << std::endl;
                return 1;
            }

            try { // checking that the user inputted a valid integer
                std::string screen_width_string = argv[(i++)+1];
                window_width = std::stoi(screen_width_string); 
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid value" << std::endl;
                return 1;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Value is out of the valid range" << std::endl;
                return 1;
            }

            if (window_width < 400) { // checking that the width is within valid bounds
                std::cerr << "Error: Width too small" << std::endl;
                return 1;
            } else if (window_width > desktop.width) {
                std::cerr << "Error: Width exceeds current screen size" << std::endl;
                return 1;
            } else {
                window_width_set = true;
            }
        } else if (arg == "-H" || arg == "--height") {
            if (window_height_set) {
                std::cerr << "Error: Window height already set" << std::endl;
                return 1;
            } 
            if (argc <= i+1) {
                std::cerr << "Error: Missing screen height" << '\n';
                std::cout << "Usage: vis-sort -H <height>" << std::endl;
                return 1;
            }

            try {  // checking that the user inputted a valid integer
                std::string screen_height_string = argv[(i++)+1];
                window_height = std::stoi(screen_height_string); 
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid value" << std::endl;
                return 1;
            } catch (const std::out_of_range& e) {
                std::cerr << "Error: Value is out of the valid range" << std::endl;
                return 1;
            }

            if (window_height < 200) {  // checking that the height is within the valid bounds
                std::cerr << "Error: Height too small" << std::endl;
                return 1;
            } else if (window_height > desktop.height) {
                std::cerr << "Error: Height exceeds current screen size" << std::endl;
                return 1;
            } else {
                window_height_set = true;
            }
        } else {
            std::cerr << "Invalid option" << std::endl;
            return 1;
        }
    }
    if (!data_point_set) {
        data_point_count = 200;
    }
    if (!window_height_set && !window_width_set) {
        window_width = 800;
        window_height = 800;
    } else if (!window_height_set) {
        window_height = window_width;  // default to a 1:1 resolution
    } else if (!window_width_set) {
        window_width = window_height;
    }
    if (data_point_count > window_width || data_point_count > window_height) {
        std::cerr << "Error: Too many data points to display on screen" << std::endl;
        return 1;
    }

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "VisSort", sf::Style::Close);
    window.setSize(sf::Vector2u(window_width, window_height)); 
    window.setPosition(sf::Vector2i(0, 0));
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
