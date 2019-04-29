#include "Utils.h"

const string toTime(const int value)
{
    string minutes;
    string seconds;
    string time;
    minutes = to_string(value / MINUTE_MULTIPLIER);
    seconds = to_string(value % MINUTE_MULTIPLIER);

    if (seconds == "0")
    {
        seconds = "00";
    }
    else if (seconds.length() == ONE_DIGIT)
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
    vector<string> values = split(value, DELIMITER);
    return ((stoi(values[MINUTE_INDEX])*MINUTE_MULTIPLIER) + stoi(values[SECOND_INDEX]));
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




