#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>
#include <vector>
using namespace std;

#include "LetterFrequency.h"
using namespace model;

namespace controller
{

/**
* The controller class that controls the communication between the model and view classes
* @authors Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class Controller
{

private:
    LetterFrequency letterFrequency;
public:
    /**
    * Creates a new controller object
    * @preconditon none
    * @postcondition a new controller object is created
    */
    Controller();

    /**
    * Destructs the controller object
    */
    virtual ~Controller();

    /**
    * Gets the letters to display
    * @param numberOfLettersToGenerate the number of letters to generate
    * @precondition none
    * @return the desired number of letters to display
    *
    */
    vector<string> getLettersToDisplay(const int numberOfLettersToGenerate);

    /**
    * Gets the given letters in a new shuffled order =
    * @param letters the letters to shuffle
    * @precondition none
    * @return the shuffled collection of letters
    */
    vector<string> getShuffledLetters(vector<string> letters);


};

}

#endif // CONTROLLER_H
