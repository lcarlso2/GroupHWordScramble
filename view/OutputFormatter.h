#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

#include "Utils.h"

#include "PlayerScore.h"
using namespace model;

namespace view
{

/**
* the output formatter class responsible for formatting output
* @author Lucas Carlson and Carson Bedrosian
* @version 4/20/2019
*
*/
class OutputFormatter
{

private:
    string formatUnderscoresForWord(string word);

public:
    /**
    * Creates a new output formatter
    * @precondition none
    * @postcondition a new output formatter is created
    */
    OutputFormatter();

    /**
    * Formats the given PlayerScore objects
    * @precondition none
    * @postcondition none
    * @param scores The PlayerScores to be formatted
    * @return The formatted output for scores
    */
    string formatScores(vector<PlayerScore> scores);

    /**
    * Formats the given map of words and associated points
    * @param words the words and their points
    * @precondition none
    * @return the formatted string
    */
    string formatWords(map<string, int> words);

    string formatRemainingWords(const int totalWords, const int wordsGuessed);

    string formatUnderscoresForPossibleWords(unordered_set<string> words,map<string, int> guessedWords);

    /**
    * Destructs the output formatter
    */
    virtual ~OutputFormatter();




};

}
#endif // OUTPUTFORMATTER_H
