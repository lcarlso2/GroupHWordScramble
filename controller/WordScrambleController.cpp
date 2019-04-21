#include "WordScrambleController.h"


namespace controller
{

WordScrambleController::WordScrambleController()
{

}

WordScrambleController::~WordScrambleController()
{
    //dtor
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
    vector<string> letters = this->letterFrequency.getRandomLetters(numberOfLettersToGenerate);
    return letters;

}

vector<string> WordScrambleController::getShuffledLetters(vector<string> letters)
{
    return this->letterFrequency.shuffleLetters(letters);
}

int WordScrambleController::getPointsForWord(const string& word, const int currentPoints)
{
    int wordLength = word.length();
    int pointsPerLetter;
    switch(wordLength)
    {
    case 3:
        pointsPerLetter = 20;
        break;
    case 4:
        pointsPerLetter = 30;
        break;
    case 5:
        pointsPerLetter = 40;
        break;
    case 6:
        pointsPerLetter = 50;
        break;
    case 7:
        pointsPerLetter = 60;
        break;
    }
    return (word.length() * pointsPerLetter) + currentPoints;
}

void WordScrambleController::loadDictionary()
{
    this->validWords = this->dictionaryFileReader.getValidWords();

}

bool WordScrambleController::checkThatWordWasNotAlreadyGuessed(const string& word)
{
    return this->guessedWords.count(word) == WORD_ALREADY_GUESSED;
}

bool WordScrambleController::checkWord(const string& word)
{
    if (this->possibleWords.count(word) == WORD_IS_VALID)
    {
        this->guessedWords.insert({word, this->getPointsForWord(word, 0)});
        return WORD_IS_VALID;
    }
    else
    {
        return WORD_IS_NOT_VALID;
    }
}

int WordScrambleController::getWordsRemaining(){
    return this->possibleWords.size() - this->guessedWords.size();
}

int WordScrambleController::getTotalNumberOfWords(){
    return this->possibleWords.size();
}
string WordScrambleController::getFormattedWordsAndTheirPoints() {
    return this->formatter.formatWords(this->guessedWords);
}

string WordScrambleController::getFormattedHighScores()
{
    map<string, vector<int>> scores = this->scoreFileReader.readFile();
    string output = this->formatter.formatScores(scores);
    return this->formatter.formatScores(scores);
}

void WordScrambleController::resetWords(const string& word) {
    this->possibleWords = findAllValidWords(word);
}

}
