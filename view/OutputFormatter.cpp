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
        builder << "Word: " << currentWord.first << "-" << currentWord.second << " points" << endl;
    }
    return builder.str();
}

string OutputFormatter::formatScores(vector<PlayerScore> scores)
{
    stringstream builder;
    builder << left << setw(28) << "NAME" << left << setw(28) << "SCORE" << right << setw(0) << "TIME" << endl;
    for (auto& currentScore : scores)
    {
        builder << left << setw(28) << currentScore.getName() << left << setw(28) << currentScore.getScore() << right << setw(0) << toTime(currentScore.getTime()) << endl;
    }

    return builder.str();
}

string OutputFormatter::formatRemainingWords(const int totalWords, const int wordsGuessed)
{
    return to_string(wordsGuessed) + "/" + to_string(totalWords);
}

string OutputFormatter::formatWordsToDisplayDuringGame(map<string, string> words, map<string, int> guessedWords)
{
    stringstream builder;

    int columnCount = 0;
    for (auto& word : words)
    {
        if (guessedWords.count(word.first) != 0)
        {
            string guessedWordAndPoints = word.first + "-" + to_string(guessedWords[word.first]) + " points";
            builder << left << setw(20) << guessedWordAndPoints;
        }
        else
        {
            builder << left << setw(20) << word.second;
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

}
