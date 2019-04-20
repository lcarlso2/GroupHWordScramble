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


map<string, vector<int, int>> HighScoreFileReader::readFile()
{
    map<string, vector<int, int>> scores;
    ifstream inFile;
    inFile.open(FILE_NAME);
    vector<string> lines;
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
        }
    }

    inFile.close();
    return newMap;
}
}
