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

void WordScrambleController::intializeGameLogic(){
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

void WordScrambleController::setButtonCount(const int buttonCount){
    this->settings.setButtonCount(buttonCount);
}

void WordScrambleController::setTimerCount(const int timerCount) {
    this->settings.setTimerCount(timerCount);
}

void WordScrambleController::writeSettingsToFile()
{
    TextFileWriter writer;
    writer.writeSettingsToFile(this->settings.getButtonCount(), this->settings.getTimerCount());
}

vector<string> WordScrambleController::getLettersToDisplay(const int numberOfLettersToGenerate)
{
    return this->logic.getLettersForRound(numberOfLettersToGenerate);
}

vector<string> WordScrambleController::getShuffledLetters(vector<string> letters)
{
    return this->logic.shuffle(letters);
}

void WordScrambleController::addScoreForWord(const string& word)
{
    this->logic.addScore(word);
}

void WordScrambleController::decrementScore(const int pointsToRemove)
{
    this->logic.decrementScore(pointsToRemove);
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
    return this->logic.getWordsRemaining() == 0;
}

void WordScrambleController::setPossibleWords(const string& characters)
{
    this->logic.setPossibleWords(characters);
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

string WordScrambleController::getHintsToDisplay(){
    return this->formatter.formatUnderscoresForPossibleWords(this->logic.getPossibleWords(), this->logic.getGuessedWords());
}


}
