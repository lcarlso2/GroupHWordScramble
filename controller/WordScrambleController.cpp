#include "WordScrambleController.h"


namespace controller
{

WordScrambleController::WordScrambleController()
{

}

WordScrambleController::~WordScrambleController()
{

}

int WordScrambleController::getNumberOfLetters()
{
    this->settingsFileReader.getNumberOfLetters();

}

int WordScrambleController::getTimer()
{
    this->settingsFileReader.getTimer();
}

void WordScrambleController::writeSettingsToFile(const int numberOfLetters, const int timer)
{
    SettingsFileWriter writer;
    writer.writeSettingsToFile(numberOfLetters, timer);
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

void WordScrambleController::setPossibleWords(const string& characters)
{
    this->logic.setPossibleWords(characters);
}

string WordScrambleController::getFormattedWordsAndTheirPoints()
{
    return this->formatter.formatWords(this->logic.getGuessedWords());
}

string WordScrambleController::getFormattedHighScores()
{
    map<string, vector<int>> scores = this->scoreFileReader.readFile();
    string output = this->formatter.formatScores(scores);
    return this->formatter.formatScores(scores);
}


}
