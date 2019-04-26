#include "HighScoreBoard.h"

namespace model
{

bool compareByScore(PlayerScore scoreOne, PlayerScore scoreTwo){
    return (scoreOne.getScore() > scoreTwo.getScore());
}

bool compareByScoreAndTime(PlayerScore scoreOne, PlayerScore scoreTwo) {
    return ((scoreOne.getScore() > scoreTwo.getScore()) || (scoreOne.getScore() == scoreTwo.getScore() && scoreOne.getTime() < scoreTwo.getTime()));
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
    for (int index = 0; index < number; index++)
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


}
