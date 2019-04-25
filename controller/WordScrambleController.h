#ifndef WORDSCRAMBLECONTROLLER_H
#define WORDSCRAMBLECONTROLLER_H

#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

#include "GameLogic.h"
#include "PlayerScore.h"
#include "HighScoreBoard.h"
#include "Settings.h"
using namespace model;

#include "TextFileWriter.h"
#include "TextFileReader.h"
using namespace io;

#include "OutputFormatter.h"
using namespace view;

#include "Utils.h"

namespace controller
{

const int WORD_IS_VALID = 1;
const int WORD_IS_NOT_VALID = 0;
const int WORD_ALREADY_GUESSED = 1;
const int AMOUNT_TO_DECREMENT_POINTS_BY = 10;
const int NO_WORDS_LEFT = 0;
/**
* The controller class that controls the communication between the model and view classes
* @authors Lucas Carlson and Carson Bedrosian
* @version 4/12/2019
*/
class WordScrambleController
{

private:

    HighScoreBoard scoreBoard;

    TextFileReader fileReader;

    OutputFormatter formatter;

    GameLogic logic;

    LetterFrequency letterFrequency;

    Settings settings;


public:
    /**
    * Creates a new controller object
    * @preconditon none
    * @postcondition a new controller object is created
    */
    WordScrambleController();

    /**
    * Destructs the controller object
    */
    virtual ~WordScrambleController();

    /**
    * Gets the number of letters to display
    * @precondition none
    * @return the number of letters to display
    */
    int getButtonCount();

    /**
    * Gets the timer to display
    * @precondition none
    * @return the timer to display
    */
    int getTimerCount();

    /**
    * Sets the button count
    * @param buttonCount the count of buttons
    * @precondition none
    * @postcondition the button count is set
    */
    void setButtonCount(const int buttonCount);

    /**
    * Sets the timer count
    * @param timerCount the count of the timer
    * @precondition none
    * @postcondition the timer count is set
    */
    void setTimerCount(const int timerCount);

    /**
    * Writes the settings to the settings file
    * @precondition none
    * @postcondition the file is written to
    */
    void writeSettingsToFile();

    /**
    * Gets the letters  to display
    * @precondition none
    * @return the desired letters to display
    *
    */
    vector<string> getLettersToDisplay();

    /**
    * Initializes the round
    * @param numberOfCharactersToGenerate the number of characters to generate
    * @precondition none
    * @postcondition the round is set up
    *
    */
    void initializeRound(const int numberOfCharactersToGenerate);

    /**
    * Gets the given letters in a new shuffled order =
    * @param letters the letters to shuffle
    * @precondition none
    * @return the shuffled collection of letters
    */
    vector<string> getShuffledLetters(vector<string> letters);

    /**
    * Add the points for the word
    * @param word the word
    * @precondition none
    * @return the points for the word
    */
    void addScoreForWord(const string& word);

    /**
    * Decrements the score by the desired amount
    * @precondition none
    * @postcondition the score is decremented
    */
    void decrementScore();

    /**
    * Gets the total score
    * @precondition none
    * @return the the total score
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
    * Get the output for the guessed words and their points
    * @precondition none
    * @return the formatted output
    */
    string getFormattedWordsAndTheirPoints();

    /**
    * Gets the output for the high scores
    * @precondition none
    * @postcondition none
    * @return Formatted highscores
    */
    string getInitialHighScores();

    /**
    * Gets the count of the words remaining formatted for output
    * @precondition none
    * @return the count of the words remaining formatted for  ouput
    */
    string getWordsRemainingCountFormatted();

    /**
    * Checks if there are remaining words
    * @precondition none
    * @return true if there are no remaining words to guess otherwise false
    */
    bool checkForNoRemainingWords();

    /**
    * Gets the output to display during game
    * @precondition none
    * @return the output to display during game
    */
    string getWordsToDisplay();

    /**
    * Initialize the game logic
    * @precondition none
    * @postcondition the game logic is initialized
    */
    void initializeGameLogic();

    /**
    * Adds a new PlayerScore object to this->scoreBoard
    * @precondition none
    * @postcondition Score is added
    * @param name Name of the player
    * @param score Score that the player achieved
    * @param time Time allotted for the game
    */
    void addNewScore(const string& name, int score, int time);



};

}

#endif // CONTROLLER_H
