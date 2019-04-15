#include "Controller.h"

#include <iostream>

namespace controller
{

Controller::Controller()
{
    //ctor
}

Controller::~Controller()
{
    //dtor
}


vector<string> Controller::getLettersToDisplay(const int numberOfLettersToGenerate)
{
    vector<string> letters = this->letterFrequency.getRandomLetters(numberOfLettersToGenerate);
    return letters;

}

vector<string> Controller::getShuffledLetters(vector<string> letters)
{
    return this->letterFrequency.shuffleLetters(letters);
}

int Controller::getPointsForWord(const int charactersInWord) {
   // int letterCount = word.length();

    string test = "test";

    cout << charactersInWord << endl;

    return charactersInWord * 10;
}

}
