#include "OutputFormatter.h"

#include <iostream>
namespace view
{
OutputFormatter::OutputFormatter()
{
    //ctor
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

string OutputFormatter::formatWords(map<string, int> words)
{
    stringstream builder;
    for (auto& currentWord : words)
    {
        builder << "Word: " << currentWord.first << "-" << currentWord.second << " point(s)" << endl;
    }
    return builder.str();
}

string OutputFormatter::formatScores(vector<PlayerScore> scores)
{
    stringstream builder;
    builder << left << setw(10) << "Name" << left << setw(10) << "Score" << left << setw(10) << "Time" << endl;
    for (auto& currentScore : scores)
    {
        builder << left << setw(10) << currentScore.getName() << left << setw(10) << currentScore.getScore() << left << setw(10) << currentScore.getTime() << endl;
    }

    return builder.str();
}

string OutputFormatter::formatRemainingWords(const int totalWords, const int wordsGuessed)
{
    return to_string(wordsGuessed) + "/" + to_string(totalWords);
}

string OutputFormatter::formatWordsToDisplayDuringGame(unordered_set<string> words, map<string, int> guessedWords)
{
    stringstream builder;

    int columnCount = 0;
    for (auto& word : words)
    {
        if (guessedWords.count(word) != 0)
        {
            string guessedWordAndPoints = word + "-" + to_string(guessedWords[word]) + " points";
            builder << left << setw(20) << guessedWordAndPoints;
        }
        else
        {
            builder << left << setw(20) << this->formatUnderscoresForWord(word.c_str());
        }

        if (columnCount == 2)
        {
            builder << endl;
            columnCount = 0;
        }
        columnCount++;
    }

    return builder.str();

}

string OutputFormatter::formatUnderscoresForWord(string word)
{
    stringstream builder;
    for (size_t indexOfCharacter = 0; indexOfCharacter < word.size(); indexOfCharacter++)
    {
        builder << "*";
    }

    int randomIndex = generateRandomNumber(0,word.size() - 1);
    string characterToInsert(1,word[randomIndex]);
    string stringWithNoHint = builder.str();
    string stringWithHintInIt = stringWithNoHint.replace(randomIndex, 1, characterToInsert.c_str());
    return stringWithHintInIt;


}

}
