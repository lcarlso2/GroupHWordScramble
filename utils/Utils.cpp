#include "Utils.h"

#include <iostream>
#include <unordered_set>
using namespace std;

const string toTime(const int value)
{
    string minutes;
    string seconds;
    string time;
    minutes = to_string(value / 60);
    seconds = to_string(value % 60);

    if (seconds == "0")
    {
        seconds = "00";
    }
    else if (seconds.length() == 1)
    {
        seconds = "0" + seconds;
    }
    return minutes + ":" + seconds;
}

const int generateRandomNumber(const int lowerBound, const int upperBound) {
    random_device randomGenerator;
    mt19937 mt(randomGenerator());
    uniform_int_distribution<int> distribution(lowerBound, upperBound);
    return distribution(mt);
}




