#include "TextFileReader.h"
#include "iostream"

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
        string word = data[index].erase(data[index].length() - OFFSET_OF_UNNEEDED_CHARACTER);
        if (this->determineIfWordIsValid(word))
        {
            words.insert(word);
        }
    }
    return words;
}

bool TextFileReader::determineIfWordIsValid(const string& word)
{
    bool wordIsValid = false;
    if (this->determineIfWordLengthIsValid(word))
    {
        wordIsValid = this->determineIfCharactersAppearAppropriateAmountOfTimes(word);
    }

    return wordIsValid;
}

bool TextFileReader::determineIfCharactersAppearAppropriateAmountOfTimes(const string& word)
{
    for (int indexOfLetter = 0; indexOfLetter < word.length(); indexOfLetter++)
    {
        string character(1,word[indexOfLetter]);
        if (count(word.begin(), word.end(), word[indexOfLetter]) >= LETTER_FREQUENCIES.find(character)->second)
        {
            return false;
        }
    }
    return true;
}

bool TextFileReader::determineIfWordLengthIsValid(const string& word)
{
    return (word.length() >= MININUM_NUMBER_OF_CHARACTERS && word.length() < MAX_NUMBER_OF_CHARACTERS);
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
