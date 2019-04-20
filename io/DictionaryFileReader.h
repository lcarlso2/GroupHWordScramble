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


public:

    //Creates a new dictionary file reader object
    //@precondition none
    //@postcondition a new file reader is created
    DictionaryFileReader();

    //Destructs the dictionary file reader objects
    virtual ~DictionaryFileReader();

    //Reads the file
    //@param fileName the name of the file to read
    //@precondition none
    //@return true if the file was read otherwise false
    bool readFile();

    //Parses the input from the specified filename
    //@precondition none
    //@return the input from the file as a list of baseball cards
    unordered_set<string> parseInput();

};



}


#endif // DICTIONARYFILEREADER_H
