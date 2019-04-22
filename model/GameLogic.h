#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "LetterFrequency.h"

#include "DictionaryFileReader.h"
using namespace io;



namespace model
{

const int WORD_IS_VALID = 1;
const int WORD_IS_NOT_VALID = 0;
const int WORD_ALREADY_GUESSED = 1;

/**
* The game logic class that controls the game
* @author Lucas Carlson and Carson Bedrosian
* @version 4/22/2019
*
*/
class GameLogic
{
private:
    LetterFrequency letterFrequency;

    unordered_set<string> validWords;

    map<string, int> guessedWords;

    unordered_set<string> possibleWords;

    int totalScore;

    int getPointsForWord(const string& word);

    bool isPossible(string word, string letters);

    unordered_set<string> findAllValidWords(string letters);

public:

    /**
    * Creates a new game logic
    * @precondition none
    * @postcondition a new game logic object is created
    */
    GameLogic();

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
    * Gets the letters for the round
    * @param numberOfLettersToGenerate the number of letters to generate
    * @precondition none
    * @return the desired number of letters for the round
    *
    */
    vector<string> getLettersForRound(const int numberOfLettersToGenerate);

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
    * @precondition none
    * @postcondition the score for word is added to the total score
    */
    void addScore(const string& word);

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
    * Sets the possible words to guess from
    * @param characters the characters being used to generate the possible words
    * @precondition none
    * @postcondition the possible words are set
    */
    void setPossibleWords(const string& characters);

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
