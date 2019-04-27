#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "LetterFrequency.h"
#include "Utils.h"

#include <numeric>
using namespace std;



namespace model
{

const bool WORD_IS_VALID = true;
const bool WORD_IS_NOT_VALID = false;
const bool WORD_ALREADY_GUESSED = true;
const int MININUM_NUMBER_OF_WORDS = 10;
const int INITIAL_COUNT = 1;
const int POINT_MULTIPLIER = 10;
const int ONE_INDEX = 1;
const int LOWER_BOUND = 0;
const int DEFAULT_STARTING_SCORE = 0;

/**
* The game logic class that controls the game
* @author Carson Bedrosian and Lucas Carlson
* @version 4/22/2019
*
*/
class GameLogic
{
private:
    LetterFrequency letterFrequency;

    vector<string> letters;

    unordered_set<string> dictionaryOfWords;

    map<string, int> guessedWords;

    unordered_set<string> guessedBonusWords;

    unordered_set<string> possibleWords;

    unordered_set<string> bonusWords;

    map<string, string> possibleWordsWithHints;

    int totalScore;

    int getPointsForWord(const string& word, const int bonus = 0);

    bool isPossible(string word, string letters);

    unordered_set<string> findAllPossibleWords(string letters);

    map<string, string> generatePossibleWordsWithHints(unordered_set<string> words);

    string generateHintsForWord(string word);

    void seperatePossibleAndBonusWords(unordered_set<string> words, const int seperator, unordered_set<string>& possible, unordered_set<string>& bonus);

public:

    /**
    * Creates a new game logic
    * @precondition none
    * @postcondition a new game logic object is created
    */
    GameLogic();

    /**
    * Creates a new game logic
    * @precondition none
    * @postcondition a new game logic object is created
    * @param words The dictionary words
    */
    GameLogic(unordered_set<string> words);

    /**
    * Destructs the game logic object
    */
    virtual ~GameLogic();

    /**
    * Gets the guessed words
    * @precondition none
    * @return the guessed words
    */
    map<string, int> getGuessedWords();

    /**
    * Gets the letters for that round
    * @precondition none
    * @return the letters for the round
    *
    */
    vector<string> getLetters();

    /**
    * Gets the possible words with their hints
    * @precondition none
    * @return the possible words with their hints
    */
    map<string, string> getPossibleWordsWithHints();

    /**
    * Initializes the words and letters for the round
    * @param numberOfLettersToGenerate the number of letters to generate
    * @precondition none
    * @postcondition the words and letters for the round are initialized
    *
    */
    void initializeRound(const int numberOfLettersToGenerate);

    /**
    * Shuffles the given letters
    * @param letters the letters to shuffle
    * @precondition none
    * @return the shuffled collection of letters
    */
    vector<string> shuffle(vector<string> letters);

    /**
    * Add points for the given word
    * @param word the word
    * @param bonus the bonus points for the word, default is zero
    * @precondition none
    * @postcondition the score for word is added to the total score
    */
    void addScore(const string& word, const int bonus = 0);

    /**
    * Decrements the score by the desired amount
    * @param pointsToRemove the amount of points to remove
    * @precondition none
    * @postcondition the points are decremented
    */
    void decrementScore(const int pointsToRemove);

    /**
    * Gets the total score
    * @precondition none
    * @return the total score
    */
    int getTotalScore();

    /**
    * Checks that the given word is in the dictionary
    * @param word the word to check
    * @precondition none
    * @return true if the word is present otherwise false
    */
    bool checkWord(const string& word);

    /**
    * Checks that the word was not already guessed
    * @param word the word to check
    * @precondition none
    * @return true if the word was guessed otherwise false
    */
    bool checkThatWordWasNotAlreadyGuessed(const string& word);

    /**
    * Check that the given word is a bonus word
    * @param word the word to check
    * @precondition none
    * @return true if the word is a bonus word otherwise false
    *
    */
    bool checkThatWordIsBonusWord(const string& word);

    /**
    * Sets the possible words to guess from
    * @param characters the characters being used to generate the possible words
    * @precondition none
    * @postcondition the possible words are set
    */
    void setPossibleWords(vector<string> characters);

    /**
    * Gets the number of remaining words
    * @precondition none
    * @return the number of words remaining
    */
    int getWordsRemaining();

    /**
    * Gets the total number of words
    * @precondition none
    * @return the total number of words
    */
    int getTotalNumberOfWords();

};

}

#endif // GAMELOGIC_H
