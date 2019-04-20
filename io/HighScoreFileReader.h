#ifndef HIGHSCOREFILEREADER_H
#define HIGHSCOREFILEREADER_H

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include <vector>
#include <map>
using namespace std;

namespace io
{

const string FILE_NAME = "HighScores";
const int INDEX_OF_SETTINGS = 0;
const int INDEX_OF_NUMBER_OF_LETTERS = 0;
const int INDEX_OF_TIMER = 1;
const char COMMA = ',';

class HighScoreFileReader
{
    private:

    public:
        HighScoreFileReader();
        virtual ~HighScoreFileReader();

        map<string, vector<int, int>> readFile();


};
}
#endif // HIGHSCOREFILEREADER_H
