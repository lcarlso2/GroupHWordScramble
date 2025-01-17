#ifndef PLAYERSCORE_H
#define PLAYERSCORE_H

#include <string>
using namespace std;

namespace model
{

/**
* The player score class that keeps track of the player score
* @author Lucas Carlson and Carson Bedrosian
* @version 4/25/2019
*/
class PlayerScore
{
private:
    string name;
    int score;
    int time;

public:

    /**
    * Creates a PlayerScore object with the given name score and time
    * @precondition none
    * @postcondition this->name == name && this->score == score && this->time == time
    * @param name The name of the player
    * @param score The score for the game
    * @param time The allotted time for the game
    */
    PlayerScore(string name, int score, int time);

    /**
    * Clears resources associated with PlayerScore object
    */
    virtual ~PlayerScore();

    /**
    * Returns the score
    * @precondition none
    * @postcondition none
    * @return Returns the score
    */
    int getScore();

    /**
    * Returns the time
    * @precondition none
    * @postcondition none
    * @return Returns the time
    */
    int getTime();

    /**
    * Returns the name
    * @precondition none
    * @postcondition none
    * @return Returns the name
    */
    string getName();



};
}
#endif // PLAYERSCORE_H
