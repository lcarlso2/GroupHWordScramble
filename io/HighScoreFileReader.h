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
