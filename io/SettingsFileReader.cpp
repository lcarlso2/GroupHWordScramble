#include "SettingsFileReader.h"


namespace io
{
SettingsFileReader::SettingsFileReader()
{

}

SettingsFileReader::~SettingsFileReader()
{

}

void SettingsFileReader::readFile()
{
    ifstream inFile;
    inFile.open(SETTINGS_FILE_NAME);
    vector<string> input;
    string str;
    while (getline(inFile, str))
    {
        input.push_back(str);
    }

    vector<string> settings = this->split(input[INDEX_OF_SETTINGS], ',');

    this->numberOfLetters = stoi(settings[INDEX_OF_NUMBER_OF_LETTERS]);
    this->timer = stoi(settings[INDEX_OF_TIMER]);

    inFile.close();
}

vector<string> SettingsFileReader::split(const string& stringToSplit, char delimiter)
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

int SettingsFileReader::getNumberOfLetters()
{
    this->readFile();
    return this->numberOfLetters;
}

int SettingsFileReader::getTimer()
{
    this->readFile();
    return this->timer;
}

}
