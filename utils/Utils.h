#ifndef UTILS_H
#define UTILS_H

#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int MINUTE_INDEX = 0;
const int SECOND_INDEX = 1;
const int MINUTE_MULTIPLIER = 60;
const char DELIMITER = ':';
const int ONE_DIGIT = 1;

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
* Splits the given string on the given delimiter
* @param stringToSplit the string being split
* @param delimiter the delimiter
* @precondition none
* @return the string split into a vector
*/
vector<string> split(const string& stringToSplit, char delimiter);

#endif // UTILS_H
