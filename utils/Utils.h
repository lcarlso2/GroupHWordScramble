#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
* Converts the integer value into a formatted time string
* @precondition none
* @return a formatted time string
*/
const string toTime(const int value);

vector<string> permute(string str, string out, vector<string> words);


#endif // UTILS_H
