#ifndef LETTERFREQUENCY_H
#define LETTERFREQUENCY_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

#include "Utils.h"


namespace model
{

const int TEST = 1;
static const map<string, int> LETTER_FREQUENCIES =
{
    {"e", 11},
    {"t", 9},
    {"o", 8},
    {"a", 6},
    {"i", 6},
    {"n", 6},
    {"s", 6},
    {"h", 5},
    {"r", 5},
    {"l", 4},
    {"d", 3},
    {"u", 3},
    {"w", 3},
    {"y", 3},
    {"b", 2},
    {"c", 2},
    {"f", 2},
    {"g", 2},
    {"m", 2},
    {"p", 2},
    {"v", 2},
    {"j", 1},
    {"k", 1},
    {"q", 1},
    {"x", 1},
    {"z", 1}
};
/**
* The letter frequency class in charge of keep track the letters
* @author Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class LetterFrequency
{

private:

    vector<string> letters;

    vector<string> createFrequency(vector<string> letters, const int numberOfTimes, const string& letterToAdd);

public:
    /**
    * Creates a new letter frequency object
    * @precondition none
    * @postcondition a new letter frequency object is created
    */
    LetterFrequency();

    /**
    * Destructs the letter frequency object
    */
    virtual ~LetterFrequency();

    /**
    * Gets the desired number of random letters
    * @precondition numberOfLettersToGenerate the number of letters to generate
    * @return a collection of random letters
    */
    vector<string> getRandomLetters(const int numberOfLettersToGenerate);

    /**
    * Shuffles the given letters into a random new order
    * @param letters the letters to shuffle
    * @precondition none
    * @return the shuffled collection of letters
    */
    vector<string> shuffleLetters(vector<string> letters);
};
}

#endif // LETTERFREQUENCY_H
