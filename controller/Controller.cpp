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

    return freq.getSixRandomLetters();

}

}
