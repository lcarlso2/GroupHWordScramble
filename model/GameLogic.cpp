#include "GameLogic.h"

#include <iostream>
namespace model
{

GameLogic::GameLogic()
{

}

GameLogic::GameLogic(unordered_set<string> words)
{
    this->dictionaryOfWords = words;
    this->totalScore = DEFAULT_STARTING_SCORE;
}

GameLogic::~GameLogic()
{
    //dtor
}

void GameLogic::initializeRound(const int numberOfLettersToGenerate)
{
    unordered_set<string> wordsPossibleFromCharacters;
    vector<string> lettersForRound;
    while (wordsPossibleFromCharacters.size() < numberOfLettersToGenerate)
    {
        lettersForRound = this->letterFrequency.getRandomLetters(numberOfLettersToGenerate);
        string charactersAsString;
        charactersAsString = accumulate(lettersForRound.begin(), lettersForRound.end(), charactersAsString);
        wordsPossibleFromCharacters = this->findAllPossibleWords(charactersAsString);
    }
    this->seperatePossibleAndBonusWords(wordsPossibleFromCharacters, numberOfLettersToGenerate, this->possibleWords, this->bonusWords);
    this->possibleWordsWithHints = this->generatePossibleWordsWithHints(this->possibleWords);
    this->letters = lettersForRound;
}

void GameLogic::seperatePossibleAndBonusWords(unordered_set<string> words, const int seperator, unordered_set<string>& possible, unordered_set<string>& bonus)
{
    int count = INITIAL_COUNT;
    for (auto& current : words)
    {
        if (count <= seperator)
        {
            possible.insert(current);
        }
        else
        {
            bonus.insert(current);
        }
        count++;
    }
}

map<string, string> GameLogic::generatePossibleWordsWithHints(unordered_set<string> words)
{
    map<string, string> wordsWithHints;
    for (auto& current : words)
    {
        wordsWithHints[current] = this->generateHintsForWord(current);
    }
    return wordsWithHints;
}

string GameLogic::generateHintsForWord(const string& word)
{
    stringstream builder;
    for (size_t indexOfCharacter = 0; indexOfCharacter < word.size(); indexOfCharacter++)
    {
        builder << "*";
    }
    int randomIndex = generateRandomNumber(LOWER_BOUND,word.size() - ONE_INDEX);
    string characterToInsert(ONE_INDEX,word[randomIndex]);
    string stringWithNoHint = builder.str();
    string stringWithHintInIt = stringWithNoHint.replace(randomIndex, ONE_INDEX, characterToInsert.c_str());
    return stringWithHintInIt;
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

map<string, string> GameLogic::getPossibleWordsWithHints()
{
    return this->possibleWordsWithHints;
}

    int GameLogic::getPointsForWord(const string& word, const int bonus)
{
    int points = (((word.length()) - ONE_INDEX) * POINT_MULTIPLIER) * word.length() + bonus;
    return points;
}

void GameLogic::addScore(const string& word, const int bonus)
{
    int pointsForWord = this->getPointsForWord(word, bonus);
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
    return this->guessedWords.count(word) == WORD_ALREADY_GUESSED || this->guessedBonusWords.count(word) == WORD_ALREADY_GUESSED;
}

bool GameLogic::checkThatWordIsBonusWord(const string& word)
{
    if (this->bonusWords.count(word) == WORD_IS_VALID)
    {
        this->guessedBonusWords.insert(word);
        return WORD_IS_VALID;
    }
    else
    {
        return WORD_IS_NOT_VALID;
    }
}

bool GameLogic::checkWord(const string& word)
{
    if (this->possibleWordsWithHints.count(word) == WORD_IS_VALID)
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
    return this->possibleWordsWithHints.size() - this->guessedWords.size();
}

int GameLogic::getTotalNumberOfWords()
{
    return this->possibleWordsWithHints.size();
}

void GameLogic::setPossibleWords(vector<string> characters)
{
    string charactersAsString;
    charactersAsString = accumulate(characters.begin(), characters.end(), charactersAsString);
    this->possibleWords = this->findAllPossibleWords(charactersAsString);
}

bool GameLogic::isPossible(const string& word, const string& letters)
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

unordered_set<string> GameLogic::findAllPossibleWords(const string& letters)
{
    unordered_set<string> result;
    for (auto& word : this->dictionaryOfWords)
    {
        if (this->isPossible(word, letters))
        {
            result.insert(word);
        }
    }
    return result;
}


}
