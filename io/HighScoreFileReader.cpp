#include "HighScoreFileReader.h"

namespace io
{


HighScoreFileReader::HighScoreFileReader()
{

}

HighScoreFileReader::~HighScoreFileReader()
{

}


map<string, vector<int>> HighScoreFileReader::readFile()
{
    ifstream inFile;
    inFile.open(HIGH_SCORE_FILE_NAME);
    map<string, vector<int>> scores;
    vector<string> lines;
    string line;

    while (getline(inFile, line))
    {
        lines.push_back(line);
        vector<string> values = this->split(lines[INDEX_OF_VALUES], ',');
        string name = values[INDEX_OF_NAME];
        int score = stoi(values[INDEX_OF_SCORE]);
        int timeInSeconds = stoi(values[INDEX_OF_TIME]);
        vector<int> scoreTime;
        scoreTime.push_back(score);
        scoreTime.push_back(timeInSeconds);
        scores.insert({name, scoreTime});
        lines.clear();
    }
    inFile.close();
    return scores;
}


vector<string> HighScoreFileReader::split(const string& stringToSplit, char delimiter)
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
