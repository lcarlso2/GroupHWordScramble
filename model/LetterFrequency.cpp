#include "LetterFrequency.h"

#include <iostream>

namespace model
{
LetterFrequency::LetterFrequency()
{
    for(auto const& current : LETTER_FREQUENCIES)
    {
        this->letters = this->createFrequency(this->letters, current.second, current.first);
    }
}

LetterFrequency::~LetterFrequency()
{
    //dtor
}

vector<string> LetterFrequency::getRandomLetters(const int numberOfLettersToGenerate)
{
    vector<string> possibleLetters;
    set<int> randomNumbersChosen;

    random_device randomGenerator;
    mt19937 mt(randomGenerator());
    uniform_int_distribution<int> distribution(0, 96);

    while (randomNumbersChosen.size() < numberOfLettersToGenerate)
    {
        int randomIndex = distribution(mt);
        randomNumbersChosen.insert(randomIndex);
    }

    for (auto& indexOfLetter : randomNumbersChosen)
    {
        possibleLetters.push_back(this->letters[indexOfLetter]);
    }
    return possibleLetters;
}

vector<string> LetterFrequency::createFrequency(vector<string> letters, const int numberOfTimes, const string& letterToAdd)
{
    for (int i= 0; i < numberOfTimes; i++)
    {
        letters.push_back(letterToAdd);
    }
    return letters;
}

vector<string> LetterFrequency::shuffleLetters(vector<string> letters)
{
    random_shuffle(letters.begin(), letters.end());
    return letters;
}

}

