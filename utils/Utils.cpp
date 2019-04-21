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

vector<string> permute(int k, string &word) {
    for(int j = 1; j < word.size(); j++)
    {
        cout << "here??" << endl;
        std::swap(word[k % (j + 1)], word[j]);
        cout << word << endl;
    cout << "here??123" << endl;
        k = k / (j + 1);
        cout << "here??555" << endl;
    }
}
