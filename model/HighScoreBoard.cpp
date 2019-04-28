#include "HighScoreBoard.h"

#include <iostream>
using namespace std;
namespace model
{

bool compareByScore(PlayerScore scoreOne, PlayerScore scoreTwo)
{
    return scoreOne.getScore() > scoreTwo.getScore();
}

bool compareByScoreAndTime(PlayerScore scoreOne, PlayerScore scoreTwo)
{
    if(scoreOne.getScore() == scoreTwo.getScore())
    {
        cout << "Score One: " << scoreOne.getTime() << " Is Less Than " << scoreTwo.getTime() << " " << (scoreOne.getTime() < scoreTwo.getTime()) << endl;
        return scoreOne.getTime() < scoreTwo.getTime();
    }
    return scoreOne.getScore() > scoreTwo.getScore();

}

HighScoreBoard::HighScoreBoard()
{

}

HighScoreBoard::~HighScoreBoard()
{

}

vector<PlayerScore> HighScoreBoard::getSpecifiedNumberOfHighScores(const int number)
{
    vector<PlayerScore> highscores;
    int numberOfScores = number;
    if(number == DISPLAY_ALL_FLAG || number > this->scores.size())
    {
        numberOfScores = this->scores.size();
    }

    for (int index = 0; index < numberOfScores; index++)
    {
        highscores.push_back(this->scores[index]);
    }
    return highscores;
}


void HighScoreBoard::sortByScore()
{
    sort(this->scores.begin(), this->scores.end(), compareByScore);
}


void HighScoreBoard::sortByScoreAndTime()
{
    sort(this->scores.begin(), this->scores.end(), compareByScoreAndTime);
}

void HighScoreBoard::add(PlayerScore score)
{
    this->scores.push_back(score);
}

int HighScoreBoard::size()
{
    return this->scores.size();
}

vector<PlayerScore> HighScoreBoard::getScores()
{
    return this->scores;
}



}
