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
    this->highScores.reserve(5);
}

HighScoreBoard::~HighScoreBoard()
{

}

vector<PlayerScore> HighScoreBoard::getHighScores()
{
    return this->highScores;
}


void HighScoreBoard::sortByScore()
{
    sort(this->highScores.begin(), this->highScores.end(), scoreComparer());

}


void HighScoreBoard::sortByScoreAndTime()
{
    sort(this->highScores.begin(), this->highScores.end(), scoreAndTimeComparer());
}

void HighScoreBoard::add(PlayerScore score)
{
    this->highScores.push_back(score);
}


}
