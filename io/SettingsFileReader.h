#ifndef SETTINGSFILEREADER_H
#define SETTINGSFILEREADER_H

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

namespace io
{



/**
* The settings file reader that controls reader the settings from the file
* @author Lucas Carlson and Carson Bedrosian
* @version 4/16/2019
*/
class SettingsFileReader
{
private:
    int numberOfLetters;

    int timer;

    vector<string> split(const string& stringToSplit, char delimiter);

    void readFile();

public:

    /**
    * Creates a new settings file reader
    * @precondition none
    * @postcondition a new settings file reader is created
    */
    SettingsFileReader();

    /**
    * Destructs the settings file reader
    */
    virtual ~SettingsFileReader();

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

};
}

#endif // SETTINGSFILEREADER_H
