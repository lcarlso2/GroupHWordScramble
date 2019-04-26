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
class DictionaryCleaner
{
private:

    bool determineIfWordIsValid(const string& word);

    bool determineIfWordLengthIsValid(const string& word);

    bool determineIfCharactersAppearAppropriateAmountOfTimes(const string& word);

public:
    DictionaryCleaner();

    virtual ~DictionaryCleaner();

    unordered_set<string> generateCleanedDictionary(vector<string> words);

};

}

#endif // DICTIONARYCLEANER_H
