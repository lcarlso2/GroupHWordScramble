#include "WordScrambleController.h"


namespace controller
{

WordScrambleController::WordScrambleController()
{
    this->settings = this->fileReader.getSettingsData();
    this->scoreBoard = this->fileReader.getHighScoreData();
}

WordScrambleController::~WordScrambleController()
{

}

void WordScrambleController::initializeGameLogic()
{
    vector<string> words = this->fileReader.getDictionaryData();

    DictionaryCleaner cleaner;
    unordered_set<string> cleanedWords = cleaner.generateCleanedDictionary(words);
    this->logic = GameLogic(cleanedWords);
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

void WordScrambleController::addScoreForBonusWord(const string& word)
{
    this->logic.addScore(word, BONUS_POINTS);
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

bool WordScrambleController::checkThatWordIsBonusWord(const string& word)
{
    return this->logic.checkThatWordIsBonusWord(word);
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

string WordScrambleController::getFormattedScoresToDisplay(const int numberToDisplay)
{
    string output = this->formatter.formatScores(this->scoreBoard.getSpecifiedNumberOfHighScores(numberToDisplay));
    return output;
}

void WordScrambleController::addNewScore(const string& name, const int score, const int time)
{
    PlayerScore playerScore(name, score, time);
    this->scoreBoard.add(playerScore);
}

string WordScrambleController::getWordsToDisplay()
{
    return this->formatter.formatWordsToDisplayDuringGame(this->logic.getPossibleWordsWithHints(), this->logic.getGuessedWords());
}

void WordScrambleController::sortScoreBoardByScore()
{
    this->scoreBoard.sortByScore();
}

void WordScrambleController::sortScoreBoardByScoreAndTime()
{
    this->scoreBoard.sortByScoreAndTime();
}

int WordScrambleController::calculateAllottedTime(const int time)
{
    return (this->getTimerCount() * MINUTE_MULTIPLIER) - time;
}

void WordScrambleController::writeScoresToFile()
{
    TextFileWriter writer;
    writer.writeScoresToFile(this->scoreBoard);
}

void WordScrambleController::clearScoreBoard()
{
    this->scoreBoard.clear();
}

string WordScrambleController::getFormattedBonusWordPointsToDisplay(const string& word)
{
    int points = this->logic.getPointsForWord(word, BONUS_POINTS);
    return this->formatter.formatBonusWordPointsForDisplay(points);
}


}
