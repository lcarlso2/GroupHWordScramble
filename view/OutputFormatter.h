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

const string WORD_ALREADY_GUESSED_MESSAGE = "Word already guessed!";
const string INVALID_WORD_MESSAGE = "Invalid word! You lose 10 points";
const string GAME_WON_MESSAGE = "You won!";
const string GAME_OVER_MESSAGE = "Game over!";
const int NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_SCORES = 27;
const int NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_DISPLAYING_WORDS = 20;
const int MAX_COLUMN_COUNT = 2;
const int DEFAULT_COLUMN_COUNT = 0;
const bool WORD_IS_NOT_PRESENT = false;

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
    * Destructs the output formatter
    */
    virtual ~OutputFormatter();

    /**
    * Formats the given PlayerScore objects
    * @precondition none
    * @postcondition none
    * @param scores The PlayerScores to be formatted
    * @return The formatted output for scores
    */
    string formatScores(vector<PlayerScore> scores);

    /**
    * Formats the remaining words into *wordsLeftCount* // *totalWords*
    * @param totalWords the total number of words
    * @param wordsGuessed the number of words guessed
    * @precondition none
    * @return the formated string
    */
    string formatRemainingWords(const int totalWords, const int wordsGuessed);

    /**
    * Formats the total words with * and one letter revealed and formats the guessed words as visible with there points shown
    * @param all this words for this round
    * @param guessedWords the guessed words and their points
    * @precondition none
    * @return the formatted string
    */
    string formatWordsToDisplayDuringGame(map<string, string> words,map<string, int> guessedWords);

    /**
    * Formats bonus word points for display
    * @param points the points for the word
    * @precondition none
    * @return the formatted string
    */
    string formatBonusWordPointsForDisplay(const int points);
};

}
#endif // OUTPUTFORMATTER_H
