#include "sorter.hpp"

Sorter::Sorter(size_t size, Graphics_Engine* gfx) : graphics(gfx) {
    for (int i = 0; i < size; i++) {
        data.push_back(Datapoint(i, graphics->getSprite(i)));
    }
    rng = std::default_random_engine { rd() };

}

Sorter::~Sorter() {}

void Sorter::printData() {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << std::endl;
}

void Sorter::shuffleData() {
    std::shuffle(data.begin(), data.end(), rng);
    for (int i = 0; i < data.size(); i++) {
        data[i].setSprite(graphics->getSprite(data[i].getValue()));
    }
    updateGraphics();
}

bool Sorter::verifySort() {
    for (int i = 1; i < data.size(); i++) {
        if (data[i] <= data[i-1]) { return false; }
    }
    return true;
}

bool Sorter::verifySortGraphically() {
    data[0].getSprite()->setFillColor(sf::Color::Green);
    for (int i = 1; i < data.size(); i++) {
        data[i].getSprite()->setFillColor(sf::Color::White);
        graphics->drawFrame();
        data[i].getSprite()->setFillColor(sf::Color::Green);
        if (data[i] <= data[i-1]) {
            for (int j = 0; j < data.size(); j++) {
                graphics->setBarColor(j, sf::Color::Red);
            }
            updateGraphics();
            return false;
        }
    }
    for (int i = 0; i < data.size(); i++) {
        graphics->setBarColor(i, sf::Color::Red);
    }
    return true;
}

void Sorter::bogoSort() {
    for (int i = 0; i < data.size(); i++) {
        data[i].getSprite()->setFillColor(sf::Color(0,255,255));
    }
    while (!verifySort()) {
        shuffleData();
        graphics->drawFrame();
    }
    for (int i = 0; i < data.size(); i++) {
        data[i].getSprite()->setFillColor(sf::Color(255,0,0));
    }
}

void Sorter::updateGraphics() {
    sf::Vector2u window_size = graphics->getWindowSize();
    int bar_width = (window_size.x - 50) / data.size();
    for (int i = 0; i < data.size(); i++) {
        data[i].getSprite()->setPosition(sf::Vector2f((bar_width*i)+25,window_size.y));
    }
}

void Sorter::updateBar(int i) {
    sf::Vector2u window_size = graphics->getWindowSize();
    int bar_width = (window_size.x - 50) / data.size();
    data[i].getSprite()->setPosition(sf::Vector2f((bar_width*i)+25,window_size.y));
}

void Sorter::testEdit() {
    data[0].getSprite()->setFillColor(sf::Color(0,0,255));
}

void Sorter::insertionSort() {
    for (int i = 1; i < data.size(); i++) {
        Datapoint key = data[i];
        sf::RectangleShape* key_sprite = data[i].getSprite();
        key_sprite->setFillColor(sf::Color(0,255,255));
        int j = i - 1;
        while (j >= 0 && key < data[j]) {
            data[j].getSprite()->setFillColor(sf::Color(0,255,255));
            graphics->drawFrame();
            data[j].getSprite()->setFillColor(sf::Color(255,0,0));
            data[j+1] = data[j];
            j--;
        }
        key_sprite->setFillColor(sf::Color(255,0,0));
        data[j+1] = key;
        updateGraphics();
        graphics->drawFrame();
    }
}

void Sorter::quickSort(int L, int R) {
    if (L < R) {
        int partition_index = partition(L,R);
        quickSort(L,partition_index-1);
        quickSort(partition_index+1,R);
    }
}

int Sorter::partition(int L, int R) {
    Datapoint pivot = data[R];

    int i = (L - 1);
    pivot.getSprite()->setFillColor(sf::Color(0,255,0));
    for (int j = L; j < R; j++) {
        sf::RectangleShape* selected_sprite = data[j].getSprite();
        selected_sprite->setFillColor(sf::Color(0,255,255));
        if (data[j] <= pivot) {
            i++;
            std::swap(data[i], data[j]);
            updateGraphics();
        }
        graphics->drawFrame();
        selected_sprite->setFillColor(sf::Color(255,0,0));
    }
    pivot.getSprite()->setFillColor(sf::Color(255,0,0));
    std::swap(data[i+1], data[R]);
    updateGraphics();
    graphics->drawFrame();
    
    return (i + 1);
}

void Sorter::mergeSort(int L, int R) {
    if (L >= R) { return; }

    int mid = L + (R - L) / 2;
    mergeSort(L, mid);
    mergeSort(mid+1, R);
    merge(L, mid, R);
}

void Sorter::merge(int L, int M, int R) {
    int n1 = M - L + 1;
    int n2 = R - M;

    std::vector<Datapoint> L_array(n1), R_array(n2);

    for (int i = 0; i < n1; i++) {
        L_array[i] = data[L+i];
        data[L+i].getSprite()->setFillColor(sf::Color(0,255,255));
        graphics->drawFrame();
    }
    for (int i = 0; i < n2; i++) {
        R_array[i] = data[M + 1 + i];
        data[M+1+i].getSprite()->setFillColor(sf::Color(0,255,255));
        graphics->drawFrame();
    }


    int i = 0, j = 0;
    int k = L;
    while (i < n1 && j < n2) {
        if (L_array[i] <= R_array[j]) {
            data[k] = L_array[i];
            L_array[i++].getSprite()->setFillColor(sf::Color(0,0,0));
        } else {
            data[k] = R_array[j];
            R_array[j++].getSprite()->setFillColor(sf::Color(0,0,0));
        }
        data[k].getSprite()->setFillColor(sf::Color(255,0,0));
        data[k].getSprite()->setOutlineColor(sf::Color(255,255,255));
        updateBar(k++);
        graphics->drawFrame();
    }

    while (i < n1) {
        data[k] = L_array[i];
        L_array[i++].getSprite()->setFillColor(sf::Color(0,0,0));
        data[k].getSprite()->setFillColor(sf::Color(255,0,0));
        data[k].getSprite()->setOutlineColor(sf::Color(255,255,255));
        updateBar(k++);
        graphics->drawFrame();
    }

    while (j < n2) {
        data[k] = R_array[j];
        R_array[j++].getSprite()->setFillColor(sf::Color(0,0,0));
        data[k].getSprite()->setFillColor(sf::Color(255,0,0));
        data[k].getSprite()->setOutlineColor(sf::Color(255,255,255));
        updateBar(k++);
        graphics->drawFrame();
    }
}

void Sorter::selectionSort() {
    for (int L = 0; L < data.size(); L++) {
        int smallest = data[L].getValue();
        int idx = L;
        data[L].getSprite()->setFillColor(sf::Color::Cyan);
        for (int i = L+1; i < data.size(); i++) {
            data[i].getSprite()->setFillColor(sf::Color::Cyan);
            if (data[i] < smallest) {
                smallest = data[i].getValue();
                idx = i;
            } 
            graphics->drawFrame();
            data[i].getSprite()->setFillColor(sf::Color::Red);

        }
        data[L].getSprite()->setFillColor(sf::Color::Red);
        std::swap(data[L],data[idx]);
        updateBar(L);
        updateBar(idx);
        data[L].getSprite()->setFillColor(sf::Color::Green);
        graphics->drawFrame();
    }
    for (int i = 0; i < data.size(); i++) {
        graphics->setBarColor(i, sf::Color::Red);
    }
    updateGraphics();
}

void Sorter::bubbleSort() {
    int n = data.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            data[j].getSprite()->setFillColor(sf::Color::Cyan);
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
                updateBar(j);
                updateBar(j+1);
                swapped = true;
            } 
            graphics->drawFrame(); 
            data[j].getSprite()->setFillColor(sf::Color::Red);
        }
        graphics->setBarColor(n-i-1, sf::Color::Green);
        if (swapped == false) {
            for (int j = i; j >= 0; j--) {
                data[j].getSprite()->setFillColor(sf::Color::Green);
                graphics->drawFrame();
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        graphics->setBarColor(i, sf::Color::Red);
    }
    updateGraphics();
}