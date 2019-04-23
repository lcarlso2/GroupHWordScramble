#ifndef HIGHSCOREBOARD_H
#define HIGHSCOREBOARD_H

#include "PlayerScore.h"
using namespace model;

#include <vector>
#include <algorithm>
using namespace std;

namespace model
{

class HighScoreBoard
{
    private:

        vector<PlayerScore> scores;


    public:

        /**
        * Creates a HighScoreBoard object to store the top 5 high scores
        * @precondition none
        * @postcondition this->highScores reserves 5 spots for high scores
        */
        HighScoreBoard();

        /**
        * Clears resources associated with HighScoreBoard object
        */
        virtual ~HighScoreBoard();

        /**
        * Sorts this->highScores by score
        * @precondition none
        * @postcondition this->highScores is sorted by score
        */
        void sortByScore();

        /**
        * Sorts this->highScores by score and time
        * @precondition none
        * @postcondition this->highScores is sorted by score and time
        */
        void sortByScoreAndTime();


        /**
        * Returns the desired number of high scores
        * @precondition none
        * @postcondition none
        * @return Returns the desired number of high scores
        */
        vector<PlayerScore> getSpecifiedNumberOfHighScores(const int number);

        /**
        * Adds a PlayerScore to the scoreboard
        * @precondition none
        * @postcondition score is added
        * @param score PlayerScore to be added
        */
        void add(PlayerScore score);



};
}
#endif // HIGHSCOREBOARD_H
