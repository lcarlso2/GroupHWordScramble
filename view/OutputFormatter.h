#ifndef OUTPUTFORMATTER_H
#define OUTPUTFORMATTER_H

#include <map>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

namespace view {

/**
* the output formatter class responsible for formatting output
* @author Lucas Carlson and Carson Bedrosian
* @version 4/20/2019
*
*/
class OutputFormatter
{
    public:
        /**
        * Creates a new output formatter
        * @precondition none
        * @postcondition a new output formatter is created
        */
        OutputFormatter();

        /**
        * Formats the given map of names and scores
        * @precondition none
        * @postcondition none
        * @param scores The map of names and scores
        * @return The formatted output for scores
        */
        string formatScores(map<string, vector<int>> scores);

        /**
        * Formats the given map of words and associated points
        * @param words the words and their points
        * @precondition none
        * @return the formatted string
        */
        string formatWords(map<string, int> words);

        /**
        * Destructs the output formatter
        */
        virtual ~OutputFormatter();




};

}
#endif // OUTPUTFORMATTER_H
