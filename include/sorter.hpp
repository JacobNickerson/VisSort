#ifndef SORTER_HPP
#define SORTER_HPP

#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <climits>

#include "datapoint.hpp"
#include "graphics_engine.hpp"

using namespace std::chrono_literals;

class Sorter {
    public:
        Sorter(size_t size, Graphics_Engine* gfx);
        ~Sorter();

        void printData();

        void shuffleData();

        void bogoSort();

        bool verifySort();
        bool verifySortGraphically();

        void updateGraphics();
        void updateBar(int i);

        void insertionSort();

        void quickSort(int L, int R);

        void mergeSort(int L, int R);

        void selectionSort();

        void bubbleSort();

    private:
        std::vector<Datapoint> data;
        std::random_device rd;
        std::default_random_engine rng;
        Graphics_Engine* graphics;

        int partition(int L, int R); // used with quicksort

        void merge(int L, int M, int R); // used with mergesort

};

#endif