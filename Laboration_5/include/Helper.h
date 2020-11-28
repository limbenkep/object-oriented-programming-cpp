//
// Created by limbe on 2020-11-28.
//

#ifndef LIST_MANIPULATOR_HELPER_H
#define LIST_MANIPULATOR_HELPER_H

#include <iostream>
#include <fstream>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>
#include <numeric>
#include <functional>
#include <iterator>

using namespace std;


const int upper_limit = 2000;
const int lower_limit = 1000;

const double MAX = 2000;
const double MIN = 1000;




template<typename T>
T randomNumber()
{
    random_device rd;  // random seed
    mt19937 generator(rd()); // Initializing Mersnne Twister pseudo-random number generator

    if (std::is_same<T, int>::value) {

        uniform_int_distribution<int> randomInt(lower_limit, upper_limit);

        return randomInt(generator);
    }

    if (std::is_same<T, double>::value) {

        uniform_real_distribution<double> randomDbl(MIN, MAX);

        return randomDbl(generator);
    }
}


#endif //LIST_MANIPULATOR_HELPER_H
