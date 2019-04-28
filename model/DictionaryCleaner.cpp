#include "DictionaryCleaner.h"

namespace model
{
DictionaryCleaner::DictionaryCleaner()
{
    //ctor
}

DictionaryCleaner::~DictionaryCleaner()
{
    //dtor
}

unordered_set<string> DictionaryCleaner::generateCleanedDictionary(vector<string> words)
{
    unordered_set<string> cleanedWords;

    for (size_t index = 0; index < words.size(); index++)
    {
        string word = words[index].erase(words[index].length() - OFFSET_OF_UNNEEDED_CHARACTER);
        if (this->determineIfWordIsValid(word))
        {
            cleanedWords.insert(word);
        }
    }
    return cleanedWords;
}

bool DictionaryCleaner::determineIfWordIsValid(const string& word)
{
    bool wordIsValid = false;
    if (this->determineIfWordLengthIsValid(word))
    {
        wordIsValid = this->determineIfCharactersAppearAppropriateAmountOfTimes(word);
    }

    return wordIsValid;
}

bool DictionaryCleaner::determineIfCharactersAppearAppropriateAmountOfTimes(const string& word)
{
    for (int indexOfLetter = 0; indexOfLetter < word.length(); indexOfLetter++)
    {
        string character(1,word[indexOfLetter]);
        if (count(word.begin(), word.end(), word[indexOfLetter]) > LETTER_FREQUENCIES.find(character)->second)
        {
            return false;
        }
    }
    return true;
}

bool DictionaryCleaner::determineIfWordLengthIsValid(const string& word)
{
    return (word.length() >= MININUM_NUMBER_OF_CHARACTERS && word.length() < MAX_NUMBER_OF_CHARACTERS);
}

}
