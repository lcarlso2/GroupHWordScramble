#ifndef DICTIONARYFILEREADER_H
#define DICTIONARYFILEREADER_H


#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

namespace io
{

//The dictionary file reader that handles reading data from the dictionary file
//@author Lucas Carlson
class DictionaryFileReader
{

private:
    vector<string> input;

    void readFile();


public:

    //Creates a new dictionary file reader object
    //@precondition none
    //@postcondition a new file reader is created
    DictionaryFileReader();

    //Destructs the dictionary file reader objects
    virtual ~DictionaryFileReader();

    //Parses the input from the specified filename
    //@precondition none
    //@return the input from the file as a list of baseball cards
    unordered_set<string> getValidWords();

};



}


#endif // DICTIONARYFILEREADER_H
