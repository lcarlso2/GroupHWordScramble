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

const string FILE_NAME = "highscores";
const int INDEX_OF_NAME = 0;
const int INDEX_OF_SCORE = 0;
const int INDEX_OF_TIME = 1;
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
