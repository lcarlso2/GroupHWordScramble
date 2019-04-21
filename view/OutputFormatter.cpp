#include "OutputFormatter.h"

#include <iostream>
namespace view {
OutputFormatter::OutputFormatter()
{
    //ctor
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

string OutputFormatter::formatWords(map<string, int> words) {
    stringstream builder;
    for (auto& currentWord : words) {
        builder << "Word: " << currentWord.first << "-" << currentWord.second << " point(s)" << endl;
    }

    return builder.str();
}

string OutputFormatter::formatScores(map<string, vector<int>> scores)
{
    stringstream builder;
    int score;
    int time;
    builder << left << setw(10) << "Name" << left << setw(10) << "Score" << left << setw(10) << "Time" << endl;
    for (auto& currentScore : scores)
    {
        score = currentScore.second[0];
        time = currentScore.second[1];
        builder << left << setw(10) << currentScore.first << left << setw(10) << score << left << setw(10) << time << endl;
    }

    return builder.str();
}

}
