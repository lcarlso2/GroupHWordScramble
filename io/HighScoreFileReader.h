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

const string HIGH_SCORE_FILE_NAME = "highscores";
const int INDEX_OF_VALUES = 0;
const int INDEX_OF_NAME = 0;
const int INDEX_OF_SCORE = 1;
const int INDEX_OF_TIME = 2;
const char COMMA = ',';

class HighScoreFileReader
{
private:

    vector<string> split(const string& stringToSplit, char delimiter);

public:
    /**
    * Creates a new HighScoreFileReader object
    * @precondition none
    * @postcondition none
    */
    HighScoreFileReader();

    /**
    * Clears all resources associated with HighScoreFileReader
    */
    virtual ~HighScoreFileReader();

    /**
    * Reads a file with names, scores, and times and returns a map with that information
    * @precondition none
    * @postcondition none
    * @return Returns a map with names, scores and times
    */
    map<string, vector<int>> readFile();


};
}
#endif // HIGHSCOREFILEREADER_H
