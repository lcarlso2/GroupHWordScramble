#ifndef LETTERFREQUENCY_H
#define LETTERFREQUENCY_H

#include <string>
#include <vector>
using namespace std;

namespace model{
class LetterFrequency
{

private:

    vector<string> createFrequency(vector<string> letters, const int numberOfTimes, const string& letterToAdd);


public:
    LetterFrequency();
    virtual ~LetterFrequency();

    vector<string> getSixRandomLetters();



};
}

#endif // LETTERFREQUENCY_H
