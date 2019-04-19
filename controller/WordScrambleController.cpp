#include "WordScrambleController.h"

#include <iostream>

namespace controller
{

WordScrambleController::WordScrambleController()
{
    //ctor
}

WordScrambleController::~WordScrambleController()
{
    //dtor
}


vector<string> WordScrambleController::getLettersToDisplay(const int numberOfLettersToGenerate)
{
    vector<string> letters = this->letterFrequency.getRandomLetters(numberOfLettersToGenerate);
    return letters;

}

vector<string> WordScrambleController::getShuffledLetters(vector<string> letters)
{
    return this->letterFrequency.shuffleLetters(letters);
}

int WordScrambleController::getPointsForWord(const string& word, const int currentPoints)
{
    int wordLength = word.length();
    int pointsPerLetter;
    switch(wordLength)
    {
    case 3:
        pointsPerLetter = 20;
        break;
    case 4:
        pointsPerLetter = 30;
        break;
    case 5:
        pointsPerLetter = 40;
        break;
    case 6:
        pointsPerLetter = 50;
        break;
    case 7:
        pointsPerLetter = 60;
        break;
    }
    return (word.length() * pointsPerLetter) + currentPoints;
}

int WordScrambleController::getNumberOfLetters()
{
    this->settingsFileReader.getNumberOfLetters();

}

int WordScrambleController::getTimer()
{
    this->settingsFileReader.getTimer();
}

void WordScrambleController::writeSettingsToFile(const int numberOfLetters, const int timer)
{
    SettingsFileWriter writer;
    writer.writeSettingsToFile(numberOfLetters, timer);
}

}
