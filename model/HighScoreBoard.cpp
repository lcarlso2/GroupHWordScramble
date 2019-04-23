#include "HighScoreBoard.h"

namespace model
{


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

}


void HighScoreBoard::sortByScoreAndTime()
{

}

}
