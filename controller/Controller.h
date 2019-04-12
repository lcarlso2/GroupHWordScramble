#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
using namespace std;

#include "LetterFrequency.h"
using namespace model;

namespace controller
{
class Controller
{

private:
    LetterFrequency letterFrequency;
public:
    Controller();
    virtual ~Controller();

    vector<string> getLettersToDisplay();

    vector<string> getShuffledLetters(vector<string> letters);


};

}

#endif // CONTROLLER_H
