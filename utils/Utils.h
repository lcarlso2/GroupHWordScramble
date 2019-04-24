#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
* Converts the integer value into a formatted time string
* @precondition none
* @return a formatted time string
*/
const string toTime(const int value);

/**
* Generates a random number between the specified bounds
* @param lowerBound the lower bound
* @param upperBound the upper bound
* @precondition none
* @return a random integer between the bounds
*/
const int generateRandomNumber(const int lowerBound, const int upperBound);

#endif // UTILS_H
