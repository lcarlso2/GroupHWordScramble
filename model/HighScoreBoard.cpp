#include "HighScoreBoard.h"

namespace model
{

struct scoreComparer
{
    inline bool operator() (PlayerScore scoreOne, PlayerScore scoreTwo)
    {
        return (scoreOne.getScore() > scoreTwo.getScore());
    }
};

struct scoreAndTimeComparer
{
    inline bool operator() (PlayerScore scoreOne, PlayerScore scoreTwo)
    {
        return ((scoreOne.getScore() > scoreTwo.getScore()) || (scoreOne.getScore() == scoreTwo.getScore() && scoreOne.getTime() < scoreTwo.getTime()));
    }
};

HighScoreBoard::HighScoreBoard()
{

}

HighScoreBoard::~HighScoreBoard()
{

}

vector<PlayerScore> HighScoreBoard::getSpecifiedNumberOfHighScores(const int number)
{
    vector<PlayerScore> highscores;
    for (int index = 0; index < number; index++) {
        highscores.push_back(this->scores[index]);
    }
    return highscores;
}


void HighScoreBoard::sortByScore()
{
    sort(this->scores.begin(), this->scores.end(), scoreComparer());

}


void HighScoreBoard::sortByScoreAndTime()
{
    sort(this->scores.begin(), this->scores.end(), scoreAndTimeComparer());
}

void HighScoreBoard::add(PlayerScore score)
{
    this->scores.push_back(score);
}


}
