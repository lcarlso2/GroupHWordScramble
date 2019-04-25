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
#include <unordered_set>
using namespace std;

namespace io
{


const string HIGH_SCORE_FILE_NAME = "highscores";
const string DICTIONARY_FILE_NAME = "dictionary";
const string SETTINGS_FILE_NAME = "settings";

const int INDEX_OF_VALUES = 0;
const int INDEX_OF_NAME = 0;
const int INDEX_OF_SCORE = 1;
const int INDEX_OF_TIME = 1;
const int INDEX_OF_BUTTON_COUNT = 0;
const int INDEX_OF_TIMER_COUNT = 1;
const int OFFSET_OF_UNNEEDED_CHARACTER = 1;
const int MININUM_NUMBER_OF_CHARACTERS = 3;
const int MAX_NUMBER_OF_CHARACTERS = 8;

const char COMMA = ',';

/**
* The class responsible for reading a text file
* @author Lucas Carlson and Carson Bedrosian
* @author 4/25/2019
*
*/
class TextFileReader
{
private:

    vector<string> getDataFromFile(string fileName);

    bool determineIfWordIsValid(const string& word);

    bool determineIfWordLengthIsValid(const string& word);

    bool determineIfCharactersAppearAppropriateAmountOfTimes(const string& word);


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
    unordered_set<string> getDictionaryData();

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
