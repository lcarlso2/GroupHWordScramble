#include "WordScrambleController.h"


namespace controller
{

WordScrambleController::WordScrambleController()
{
    this->settings = this->fileReader.getSettingsData();
}

WordScrambleController::~WordScrambleController()
{

}

void WordScrambleController::initializeGameLogic()
{
    unordered_set<string> words = this->fileReader.getDictionaryData();
    this->logic = GameLogic(words);
}

int WordScrambleController::getButtonCount()
{
    return this->settings.getButtonCount();
}

int WordScrambleController::getTimerCount()
{
    return this->settings.getTimerCount();
}

void WordScrambleController::setButtonCount(const int buttonCount)
{
    this->settings.setButtonCount(buttonCount);
}

void WordScrambleController::setTimerCount(const int timerCount)
{
    this->settings.setTimerCount(timerCount);
}

void WordScrambleController::writeSettingsToFile()
{
    TextFileWriter writer;
    writer.writeSettingsToFile(this->settings.getButtonCount(), this->settings.getTimerCount());
}

vector<string> WordScrambleController::getLettersToDisplay()
{
    return this->logic.getLetters();
}

void WordScrambleController::initializeRound(const int numberOfCharactersToGenerate)
{
    return this->logic.initializeRound(numberOfCharactersToGenerate);
}

vector<string> WordScrambleController::getShuffledLetters(vector<string> letters)
{
    return this->logic.shuffle(letters);
}

void WordScrambleController::addScoreForWord(const string& word)
{
    this->logic.addScore(word);
}

void WordScrambleController::decrementScore()
{
    this->logic.decrementScore(AMOUNT_TO_DECREMENT_POINTS_BY);
}

int WordScrambleController::getTotalScore()
{
    this->logic.getTotalScore();
}

bool WordScrambleController::checkThatWordWasNotAlreadyGuessed(const string& word)
{
    return this->logic.checkThatWordWasNotAlreadyGuessed(word);
}

bool WordScrambleController::checkWord(const string& word)
{
    return this->logic.checkWord(word);
}

string WordScrambleController::getWordsRemainingCountFormatted()
{
    return this->formatter.formatRemainingWords(this->logic.getTotalNumberOfWords(), this->logic.getWordsRemaining());
}

bool WordScrambleController::checkForNoRemainingWords()
{
    return this->logic.getWordsRemaining() == NO_WORDS_LEFT;
}

string WordScrambleController::getFormattedWordsAndTheirPoints()
{
    return this->formatter.formatWords(this->logic.getGuessedWords());
}

string WordScrambleController::getInitialHighScores()
{
    this->scoreBoard = this->fileReader.getHighScoreData();
    this->scoreBoard.sortByScoreAndTime();
    string output = this->formatter.formatScores(this->scoreBoard.getSpecifiedNumberOfHighScores(5));
    return output;
}

void WordScrambleController::addNewScore(const string& name, int score, int time)
{
    PlayerScore playerScore(name, score, time);
    this->scoreBoard.add(playerScore);
}

string WordScrambleController::getWordsToDisplay()
{
    return this->formatter.formatWordsToDisplayDuringGame(this->logic.getPossibleWords(), this->logic.getGuessedWords());
}


}
