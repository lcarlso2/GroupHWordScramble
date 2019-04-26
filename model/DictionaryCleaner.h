#ifndef DICTIONARYCLEANER_H
#define DICTIONARYCLEANER_H

#include <unordered_set>
#include <string>
using namespace std;

#include "LetterFrequency.h"

namespace model
{

const int OFFSET_OF_UNNEEDED_CHARACTER = 1;
const int MININUM_NUMBER_OF_CHARACTERS = 3;
const int MAX_NUMBER_OF_CHARACTERS = 8;

/**
* the dictionary cleaner class responsible for cleaning the dictionary
* @author Lucas Carlson and Carson Bedrosian
* @version 4/26/2019
*
*/
class DictionaryCleaner
{
private:

    bool determineIfWordIsValid(const string& word);

    bool determineIfWordLengthIsValid(const string& word);

    bool determineIfCharactersAppearAppropriateAmountOfTimes(const string& word);

public:

    /**
    * Creates a new dictionary cleaner object
    * @precondition none
    * @postcondition a new dictionary cleaner is created
    */
    DictionaryCleaner();

    /**
    * Destructs the dictionary cleaner object
    */
    virtual ~DictionaryCleaner();

    /**
    * Generates the cleaned dictionary
    * @precondition none
    * @return the cleaned dictionary
    * @param words the words the cleaned dictionary is being generated from
    */
    unordered_set<string> generateCleanedDictionary(vector<string> words);

};

}

#endif // DICTIONARYCLEANER_H
