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
public:
    Controller();
    virtual ~Controller();

    vector<string> getLettersToDisplay();

private:
};

}

#endif // CONTROLLER_H
