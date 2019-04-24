#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include "PlayerScore.h"
#include "HighScoreBoard.h"
#include "Settings.h"
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

const char COMMA = ',';

class TextFileReader
{
private:

    vector<string> getDataFromFile(string fileName);
    vector<string> split(const string& stringToSplit, char delimiter);

public:

    /**
    * Creates a TextFileReader object
    *
    */
    TextFileReader();

    /**
    * Clears resources associated with TextFileReader
    */
    virtual ~TextFileReader();

    unordered_set<string> getDictionaryData();

    Settings getSettingsData();

    HighScoreBoard getHighScoreData();


};

}

#endif // TEXTFILEREADER_H
