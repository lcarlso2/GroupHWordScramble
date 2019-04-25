#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/**
* Converts the integer value into a formatted time string
* @precondition none
* @param value The integer to be converted
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

/**
* Converts a string in time format to number of seconds as an int
* @precondition none
* @postcondition none
* @param value The string to be converted
* @return Returns the converted seconds
*/
const int timeToInt(const string& value);

/**
*
*
*
*/
vector<string> split(const string& stringToSplit, char delimiter);

#endif // UTILS_H
