#include "PlayerScore.h"

namespace model
{


PlayerScore::PlayerScore(string name, int score, int time)
{
    this->name = name;
    this->score = score;
    this->time = time;
}

PlayerScore::~PlayerScore()
{
    //dtor
}


int PlayerScore::getScore()
{
    return this->score;
}


int PlayerScore::getTime()
{
    return this->time;
}

}
