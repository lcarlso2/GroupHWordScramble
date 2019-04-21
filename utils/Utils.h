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

vector<string> permute(string str, string out, vector<string> words);

void combinationEasy(string input);

unordered_set<string> printAllKLengthRec(string input, string prefix, int n, int k, unordered_set<string> words);
void printAllKLength(string input, int k,int n);


bool isPossible(string word, string letters);

unordered_set<string> findAllValidWords(string letters);




#endif // UTILS_H
