#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include <string>
#include <vector>
using namespace std;

#include "LetterFrequency.h"
using namespace model;

#include "SettingsFileReader.h"
#include "SettingsFileWriter.h"
using namespace io;

namespace controller
{

/**
* The controller class that controls the communication between the model and view classes
* @authors Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class WordScrambleController
{

private:
    LetterFrequency letterFrequency;
    SettingsFileReader settingsFileReader;
public:
    /**
    * Creates a new controller object
    * @preconditon none
    * @postcondition a new controller object is created
    */
    WordScrambleController();

    /**
    * Destructs the controller object
    */
    virtual ~WordScrambleController();

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

    /**
    * Gets the points for the word
    * @param word the word
    * @param currentPoints the current points
    * @precondition none
    * @return the points for the word
    */
    int getPointsForWord(const string& word, const int currentPoints);

    /**
    * Gets the number of letters to display
    * @precondition none
    * @return the number of letters to display
    */
    int getNumberOfLetters();

    /**
    * Gets the timer to display
    * @precondition none
    * @return the timer to display
    */
    int getTimer();

    /**
    * Writes the settings to the settings file
    * @param numberOfLetters the number of letters to display
    * @param timer the timer to display
    * @precondition none
    * @postcondition the file is written to
    */
    void writeSettingsToFile(const int numberOfLetters, const int timer);


};

}

#endif // CONTROLLER_H
