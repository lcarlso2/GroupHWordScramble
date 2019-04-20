#include "Utils.h"

#include <iostream>
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

vector<string> permute(string str, string out, vector<string> words) {

    if (str.size() == 0)
    {
        words.push_back(out);
        return words;
    }

    for (int i = 0; i < str.size(); i++)
    {
        permute(str.substr(1), out + str[0], words);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
    return words;
}
