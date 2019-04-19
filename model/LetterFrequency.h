#ifndef LETTERFREQUENCY_H
#define LETTERFREQUENCY_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
using namespace std;

namespace model
{

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
