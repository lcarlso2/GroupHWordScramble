#include "LetterFrequency.h"

#include <iostream>
namespace model{
LetterFrequency::LetterFrequency()
{
    //ctor
}

LetterFrequency::~LetterFrequency()
{
    //dtor
}

vector<string> LetterFrequency::getSixRandomLetters() {
   vector<string> letters;

   letters = this->createFrequency(letters, 11, "e");
   letters = this->createFrequency(letters, 9, "t");
   letters = this->createFrequency(letters, 8, "o");
   letters = this->createFrequency(letters, 6, "a");
   letters = this->createFrequency(letters, 6, "i");
   letters = this->createFrequency(letters, 6, "n");
   letters = this->createFrequency(letters, 6, "s");
   letters = this->createFrequency(letters, 5, "h");
   letters = this->createFrequency(letters, 5, "r");

   letters = this->createFrequency(letters, 4, "l");

   letters = this->createFrequency(letters, 3, "d");
   letters = this->createFrequency(letters, 3, "u");
   letters = this->createFrequency(letters, 3, "w");
   letters = this->createFrequency(letters, 3, "y");

   letters = this->createFrequency(letters, 2, "b");
   letters = this->createFrequency(letters, 2, "c");
   letters = this->createFrequency(letters, 2, "f");
   letters = this->createFrequency(letters, 2, "g");
   letters = this->createFrequency(letters, 2, "m");
   letters = this->createFrequency(letters, 2, "p");
   letters = this->createFrequency(letters, 2, "v");

   letters = this->createFrequency(letters, 1, "j");
   letters = this->createFrequency(letters, 1, "k");
   letters = this->createFrequency(letters, 1, "q");
   letters = this->createFrequency(letters, 1, "x");
   letters = this->createFrequency(letters, 1, "z");

   for (size_t i = 0; i< letters.size(); i++ ){
        cout << letters[i] << endl;
   }

   vector<string> possibleLetters;


   return letters;



}

vector<string> LetterFrequency::createFrequency(vector<string> letters, const int numberOfTimes, const string& letterToAdd) {
    for (int i =0; i < numberOfTimes; i++) {
        letters.push_back(letterToAdd);
    }
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
