#include "datapoint.hpp"

void Datapoint::setValue(int val) {
    value = val;
}

int Datapoint::getValue() {
    return value;
}

void Datapoint::setSprite(sf::RectangleShape* spr) {
    sprite = spr;
}

sf::RectangleShape* Datapoint::getSprite() {
    return sprite;
}

bool operator>(const Datapoint& A, const Datapoint& B) {
    return A.value > B.value;
}

bool operator<(const Datapoint& A, const Datapoint& B) {
    return A.value < B.value;
}

bool operator>=(const Datapoint& A, const Datapoint& B) {
    return A.value >= B.value;
}

bool operator<=(const Datapoint& A, const Datapoint& B) {
    return A.value <= B.value;
}

bool operator==(const Datapoint& A, const Datapoint& B) {
    return A.value == B.value;
}

std::ostream& operator<<(std::ostream& os, const Datapoint& A) {
    os << A.value;
    return os;
}