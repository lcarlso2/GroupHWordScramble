#include "LetterFrequency.h"

#include <iostream>

namespace model
{
LetterFrequency::LetterFrequency()
{
    this->letters = this->createFrequency(this->letters, 11, "e");
    this->letters = this->createFrequency(this->letters, 9, "t");
    this->letters = this->createFrequency(this->letters, 8, "o");
    this->letters = this->createFrequency(this->letters, 6, "a");
    this->letters = this->createFrequency(this->letters, 6, "i");
    this->letters = this->createFrequency(this->letters, 6, "n");
    this->letters = this->createFrequency(this->letters, 6, "s");
    this->letters = this->createFrequency(this->letters, 5, "h");
    this->letters = this->createFrequency(this->letters, 5, "r");

    this->letters = this->createFrequency(this->letters, 4, "l");

    this->letters = this->createFrequency(this->letters, 3, "d");
    this->letters = this->createFrequency(this->letters, 3, "u");
    this->letters = this->createFrequency(this->letters, 3, "w");
    this->letters = this->createFrequency(this->letters, 3, "y");

    this->letters = this->createFrequency(this->letters, 2, "b");
    this->letters = this->createFrequency(this->letters, 2, "c");
    this->letters = this->createFrequency(this->letters, 2, "f");
    this->letters = this->createFrequency(this->letters, 2, "g");
    this->letters = this->createFrequency(this->letters, 2, "m");
    this->letters = this->createFrequency(this->letters, 2, "p");
    this->letters = this->createFrequency(this->letters, 2, "v");

    this->letters = this->createFrequency(this->letters, 1, "j");
    this->letters = this->createFrequency(this->letters, 1, "k");
    this->letters = this->createFrequency(this->letters, 1, "q");
    this->letters = this->createFrequency(this->letters, 1, "x");
    this->letters = this->createFrequency(this->letters, 1, "z");
}

LetterFrequency::~LetterFrequency()
{
    //dtor
}

vector<string> LetterFrequency::getSixRandomLetters()
{
    vector<string> possibleLetters;
    set<int> randomNumbersChosen;

    random_device randomGenerator;
    mt19937 mt(randomGenerator());
    uniform_int_distribution<int> distribution(0, 97);

    while (randomNumbersChosen.size() < 6)
    {
        int randomIndex = distribution(mt);
        randomNumbersChosen.insert(randomIndex);
    }

    for (auto& indexOfLetter : randomNumbersChosen){
        possibleLetters.push_back(this->letters[indexOfLetter]);
    }

    return possibleLetters;
}

vector<string> LetterFrequency::createFrequency(vector<string> letters, const int numberOfTimes, const string& letterToAdd)
{
    for (int i =0; i < numberOfTimes; i++)
    {
        letters.push_back(letterToAdd);
    }
    return letters;
}

vector<string> LetterFrequency::shuffleLetters(vector<string> letters){
    random_shuffle(letters.begin(), letters.end());
    return letters;
}
}


//11
//9
//8
//6
//5
//4
//3
//2
//1
//e
//t
//o
//a,i,n,s
//h,r
//l
//d,u,w,y
//b,c,f,g,m,p,v
//j,k,q,x,z
