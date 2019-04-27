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
    int numberOfScores = number;
    if(number == 0 || number > this->scores.size())
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


}
