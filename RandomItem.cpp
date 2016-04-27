
#include <algorithm>
#include <ctime>
#include "RandomItem.h"


double randomize(double a, double b) {
    static std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(a, b);
    return distribution(generator);
}

int randomize(int a, int b) {
    static std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(generator);
}

int odd_randomize(int a, int b) {
    static std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(a, b);
    int result = 0;
    while(result % 2==0) {
        result = distribution(generator);
    }
    return result;
}
