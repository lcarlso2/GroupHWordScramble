#include "TextFileReader.h"

namespace io
{


TextFileReader::TextFileReader()
{

}

TextFileReader::~TextFileReader()
{

}

vector<string> TextFileReader::getDictionaryData()
{
    return this->getDataFromFile(DICTIONARY_FILE_NAME);
}

Settings TextFileReader::getSettingsData()
{
    vector<string> data = this->getDataFromFile(SETTINGS_FILE_NAME);
    vector<string> settingsData = split(data[INDEX_OF_VALUES], COMMA);

    Settings settings(stoi(settingsData[INDEX_OF_TIMER_COUNT]), stoi(settingsData[INDEX_OF_BUTTON_COUNT]));

    return settings;
}

HighScoreBoard TextFileReader::getHighScoreData()
{
    vector<string> data = this->getDataFromFile(HIGH_SCORE_FILE_NAME);
    HighScoreBoard scoreBoard;
    for(size_t index = 0; index < data.size(); index++)
    {
        vector<string> values = split(data[index], COMMA);
        string name = values[INDEX_OF_NAME];
        int score = stoi(values[INDEX_OF_SCORE]);
        int timeInSeconds = stoi(values[INDEX_OF_TIME]);
        PlayerScore playerScore(name, score, timeInSeconds);
        scoreBoard.add(playerScore);
    }
    return scoreBoard;
}

vector<string> TextFileReader::getDataFromFile(string fileName)
{
    ifstream inFile;
    inFile.open(fileName);
    vector<string> data;
    string line;

    while (getline(inFile, line))
    {
        data.push_back(line);
    }
    inFile.close();
    return data;
}

}
