#ifndef LETTERFREQUENCY_H
#define LETTERFREQUENCY_H

#include <string>
#include <vector>
#include <random>
#include <algorithm>
#include <set>
using namespace std;

namespace model{
class LetterFrequency
{

private:

    vector<string> letters;

    vector<string> createFrequency(vector<string> letters, const int numberOfTimes, const string& letterToAdd);

public:
    LetterFrequency();
    virtual ~LetterFrequency();

    vector<string> getSixRandomLetters();

    vector<string> shuffleLetters(vector<string> letters);



};
}

#endif // LETTERFREQUENCY_H
