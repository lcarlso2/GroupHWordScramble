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
    vector<string> letters = this->letterFrequency.getSixRandomLetters();
    return letters;

}

vector<string> Controller::getShuffledLetters(vector<string> letters){
    return this->letterFrequency.shuffleLetters(letters);

}

}
