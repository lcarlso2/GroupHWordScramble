#include "GameLogic.h"

#include <iostream>
namespace model
{

GameLogic::GameLogic()
{

}

GameLogic::GameLogic(unordered_set<string> words)
{
    this->validWords = words;
    this->totalScore = 0;
}

GameLogic::~GameLogic()
{
    //dtor
}

void GameLogic::initializeRound(const int numberOfLettersToGenerate)
{
    unordered_set<string> wordsPossibleFromCharacters;
    vector<string> lettersForRound;
    while (wordsPossibleFromCharacters.size() < MININUM_NUMBER_OF_WORDS)
    {
        lettersForRound = this->letterFrequency.getRandomLetters(numberOfLettersToGenerate);
        string charactersAsString;
        charactersAsString = accumulate(lettersForRound.begin(), lettersForRound.end(), charactersAsString);
        wordsPossibleFromCharacters = this->findAllPossibleWords(charactersAsString);
    }
    this->possibleWords = wordsPossibleFromCharacters;
    this->letters = lettersForRound;
}

vector<string> GameLogic::shuffle(vector<string> letters)
{
    return this->letterFrequency.shuffleLetters(letters);
}

map<string, int> GameLogic::getGuessedWords()
{
    return this->guessedWords;
}

vector<string> GameLogic::getLetters()
{
    return this->letters;
}

unordered_set<string> GameLogic::getPossibleWords()
{
    return this->possibleWords;
}

int GameLogic::getPointsForWord(const string& word)
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
    return (word.length() * pointsPerLetter);
}

void GameLogic::addScore(const string& word)
{
    int pointsForWord = this->getPointsForWord(word);
    this->totalScore += pointsForWord;
}

void GameLogic::decrementScore(const int pointsToRemove)
{
    this->totalScore -= pointsToRemove;
}

int GameLogic::getTotalScore()
{
    return this->totalScore;
}

bool GameLogic::checkThatWordWasNotAlreadyGuessed(const string& word)
{
    return this->guessedWords.count(word) == WORD_ALREADY_GUESSED;
}

bool GameLogic::checkWord(const string& word)
{
    if (this->possibleWords.count(word) == WORD_IS_VALID)
    {
        int points = this->getPointsForWord(word);
        this->guessedWords.insert({word, points});
        return WORD_IS_VALID;
    }
    else
    {
        return WORD_IS_NOT_VALID;
    }
}

int GameLogic::getWordsRemaining()
{
    return this->possibleWords.size() - this->guessedWords.size();
}

int GameLogic::getTotalNumberOfWords()
{
    return this->possibleWords.size();
}

void GameLogic::setPossibleWords(vector<string> characters)
{
    string charactersAsString;
    charactersAsString = accumulate(characters.begin(), characters.end(), charactersAsString);
    this->possibleWords = this->findAllPossibleWords(charactersAsString);
}

bool GameLogic::isPossible(string word, string letters)
{
    for (size_t index = 0; index < word.length(); index ++)
    {
        bool result = false;
        for (size_t letterIndex = 0; letterIndex < letters.length(); letterIndex++)
        {
            if (word[index] == letters[letterIndex] && (count(word.begin(), word.end(), word[index]) <= count(letters.begin(), letters.end(), letters[letterIndex]) ))
            {
                result = true;
            }
        }
        if (result == false)
        {
            return false;
        }
    }
    return true;

}

unordered_set<string> GameLogic::findAllPossibleWords(string letters)
{
    unordered_set<string> result;
    for (auto& word : this->validWords)
    {
        if (word.length() >= 3)
        {
            if (this->isPossible(word, letters))
            {

                result.insert(word);
            }
        }
    }
    return result;
}


}
