#include "Controller.h"



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

}
