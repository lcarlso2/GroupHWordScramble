#ifndef HIGHSCOREBOARD_H
#define HIGHSCOREBOARD_H

#include <vector>
using namespace std;

class HighScoreBoard
{
    private:

        vector<PlayerScore> highScores;

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
        * Returns the high scores
        * @precondition none
        * @postcondition none
        * @return Returns the high scores
        */
        vector<PlayerScore> getHighScores();

};

#endif // HIGHSCOREBOARD_H
