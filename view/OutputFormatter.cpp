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

}
