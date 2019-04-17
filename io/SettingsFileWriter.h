#ifndef SETTINGSFILEWRITER_H
#define SETTINGSFILEWRITER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


namespace io {

/**
* The settings file writer that controls writing the settings to the file so they persist
* @author Lucas Carlson and Carson Bedrosian
* @version 4/16/2019
*/
class SettingsFileWriter
{
    public:
        /**
        * Creates a new settings file writer
        * @precondition none
        * @postcondition a new settings file writer is created
        */
        SettingsFileWriter();

        /**
        * Destructs the settings file reader
        */
        virtual ~SettingsFileWriter();

        /**
        * Writes the selected settings to the file so they persist
        * @param numberOfLetters the number of letters to display
        * @param timer the timer to display
        * @precondition none
        * @postcondition the settings are written to the file
        */
        void writeSettingsToFile(const int numberOfLetters, const int timer);
};

}

#endif // SETTINGSFILEWRITER_H
