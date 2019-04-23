#include "TextFileReader.h"


namespace io
{


TextFileReader::TextFileReader()
{

}

TextFileReader::~TextFileReader()
{

}

unordered_set<string> TextFileReader::getDictionaryData()
{
    vector<string> data = this->getDataFromFile(DICTIONARY_FILE_NAME);
    unordered_set<string> words;
    for (size_t index = 0; index < data.size(); index++)
    {
        string word = data[index].erase(data[index].length()-1);
        words.insert(word);
    }
    return words;
}


vector<string> TextFileReader::getSettingsData()
{
    vector<string> data = this->getDataFromFile(SETTINGS_FILE_NAME);
    vector<string> settings = this->split(data[INDEX_OF_VALUES], COMMA);

    return settings;
}


HighScoreBoard TextFileReader::getHighScoreData()
{
    vector<string> data = this->getDataFromFile(HIGH_SCORE_FILE_NAME);
    HighScoreBoard scoreBoard;
    for(size_t index = 0; index < data.size(); index++)
    {
        vector<string> values = this->split(data[index], COMMA);
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




vector<string> TextFileReader::split(const string& stringToSplit, char delimiter)
{
    vector<string> lines;
    string line;
    istringstream tokenStream(stringToSplit);
    while (getline(tokenStream, line, delimiter))
    {
        lines.push_back(line);
    }
    return lines;
}

}
