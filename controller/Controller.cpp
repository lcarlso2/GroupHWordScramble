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


vector<string> Controller::getLettersToDisplay() {
    LetterFrequency freq;
    vector<string> letters = freq.getSixRandomLetters();
    return letters;

}

}
