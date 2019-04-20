#include "DictionaryFileReader.h"


namespace io
{

DictionaryFileReader::DictionaryFileReader()
{

}

DictionaryFileReader::~DictionaryFileReader()
{

}

bool DictionaryFileReader::readFile()
{
    ifstream inFile;
    inFile.open("dictionary");

    if(!inFile)
    {
        return false;
    }

    string str;
    while (getline(inFile, str))
    {
        str = str.erase(str.length()-1);
        this->input.push_back(str);
    }

    inFile.close();
    return true;
}

unordered_set<string> DictionaryFileReader::parseInput()
{
    unordered_set<string> words;
    for (size_t index = 0; index < this->input.size(); index++)
    {
        words.insert(this->input[index]);
    }

    return words;

}
}
