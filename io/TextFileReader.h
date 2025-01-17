#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include "PlayerScore.h"
#include "HighScoreBoard.h"
#include "Settings.h"
#include "LetterFrequency.h"
using namespace model;

#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

namespace io
{


const string HIGH_SCORE_FILE_NAME = "highscores";
const string DICTIONARY_FILE_NAME = "dictionary";
const string SETTINGS_FILE_NAME = "settings";

const int INDEX_OF_VALUES = 0;
const int INDEX_OF_NAME = 0;
const int INDEX_OF_SCORE = 1;
const int INDEX_OF_TIME = 2;
const int INDEX_OF_BUTTON_COUNT = 0;
const int INDEX_OF_TIMER_COUNT = 1;

const char COMMA = ',';

/**
* The class responsible for reading a text file
* @author Carson Bedrosian and Lucas Carlson
* @author 4/25/2019
*
*/
class TextFileReader
{
private:

    vector<string> getDataFromFile(string fileName);


public:

    /**
    * Creates a TextFileReader object
    * @precondition none
    * @postcondition a text reader is created
    */
    TextFileReader();

    /**
    * Clears resources associated with TextFileReader
    */
    virtual ~TextFileReader();

    /**
    * Gets the dictionary data
    * @precondition none
    * @return the dictionary data
    */
    vector<string> getDictionaryData();

    /**
    * Gets the settings data
    * @precondition none
    * @return the settings data
    */
    Settings getSettingsData();

    /**
    * Gets the high score data
    * @precondition none
    * @return the high score data
    *
    */
    HighScoreBoard getHighScoreData();


};

}

#endif // TEXTFILEREADER_H
