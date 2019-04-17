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

int WordScrambleController::getPointsForWord(const int charactersInWord) {
   // int letterCount = word.length();

    string test = "test";

    cout << charactersInWord << endl;

    return charactersInWord * 10;
}

int WordScrambleController::getNumberOfLetters() {
    this->settingsFileReader.getNumberOfLetters();

}

int WordScrambleController::getTimer(){
    this->settingsFileReader.getTimer();
}

void WordScrambleController::writeSettingsToFile(const int numberOfLetters, const int timer) {
    SettingsFileWriter writer;
    writer.writeSettingsToFile(numberOfLetters, timer);
}

}
