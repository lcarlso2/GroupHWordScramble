#include "Utils.h"

#include <iostream>
#include <unordered_set>
using namespace std;

const string toTime(const int value)
{
    string minutes;
    string seconds;
    string time;
    minutes = to_string(value / 60);
    seconds = to_string(value % 60);

    if (seconds == "0")
    {
        seconds = "00";
    }
    else if (seconds.length() == 1)
    {
        seconds = "0" + seconds;
    }
    return minutes + ":" + seconds;
}

const int generateRandomNumber(const int lowerBound, const int upperBound)
{
    random_device randomGenerator;
    mt19937 mt(randomGenerator());
    uniform_int_distribution<int> distribution(lowerBound, upperBound);
    return distribution(mt);
}

const int timeToInt(const string& value)
{
    vector<string> values = split(value, ':');
    return ((stoi(values[0])*60) + stoi(values[1]));
}


vector<string> split(const string& stringToSplit, char delimiter)
{
    vector<string> lines;
    string line;
    istringstream tokenStream(stringToSplit);
    while (getline(tokenStream, line, delimiter))
    {
        lines.push_back(line);
    }
    return lines;
}


string generateHintsForWord(string word)
{
    stringstream builder;
    for (size_t indexOfCharacter = 0; indexOfCharacter < word.size(); indexOfCharacter++)
    {
        builder << "*";
    }
    int randomIndex = generateRandomNumber(0,word.size() - 1);
    string characterToInsert(1,word[randomIndex]);
    string stringWithNoHint = builder.str();
    string stringWithHintInIt = stringWithNoHint.replace(randomIndex, 1, characterToInsert.c_str());
    return stringWithHintInIt;
}



