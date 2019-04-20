#include "HighScoreFileReader.h"

namespace io
{


HighScoreFileReader::HighScoreFileReader()
{
    //ctor
}

HighScoreFileReader::~HighScoreFileReader()
{
    //dtor
}


map<string, vector<int>> HighScoreFileReader::readFile()
{
    ifstream inFile;
    inFile.open(FILE_NAME);
    map<string, vector<int>> scores;
    vector<string> lines;
    vector<int> scoreTime;
    string name;
    int score;
    int timeInSeconds;

    string value;
    while (getline(inFile, value, COMMA))
    {
        lines.push_back(value);
        if(lines.size() == 3)
        {
            name = lines[INDEX_OF_NAME];
            score = lines[INDEX_OF_SCORE];
            timeInSeconds = lines[INDEX_OF_TIME];
            scoreTime.push_back(score);
            scoreTime.push_back(timeInSeconds);
            scores.insert({name, scoreTime});
            lines.clear();
            scoreTime.clear();
        }
    }
    inFile.close();
    return scores;
}
}
