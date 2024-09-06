#ifndef DATAPOINT_HPP
#define DATAPOINT_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>

class Datapoint {
    public:
        Datapoint() : value(-1), sprite(nullptr) {}
        Datapoint(int value) : value(value), sprite(nullptr) {}
        Datapoint(int value, sf::RectangleShape* sprite) : value(value), sprite(sprite) {}

        void setValue(int val);
        int  getValue();

        void setSprite(sf::RectangleShape* spr);
        sf::RectangleShape* getSprite();

        friend bool operator>(const Datapoint& A, const Datapoint& B);
        friend bool operator<(const Datapoint& A, const Datapoint& B);
        friend bool operator>=(const Datapoint& A, const Datapoint& B);
        friend bool operator<=(const Datapoint& A, const Datapoint& B);
        friend bool operator==(const Datapoint& A, const Datapoint& B);
        friend std::ostream& operator<<(std::ostream& os, const Datapoint& A);

    private:
        int value;
        sf::RectangleShape* sprite;

};

#endif