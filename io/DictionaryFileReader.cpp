#include "DictionaryFileReader.h"


namespace io
{

DictionaryFileReader::DictionaryFileReader()
{

}

DictionaryFileReader::~DictionaryFileReader()
{

}

void DictionaryFileReader::readFile()
{
    ifstream inFile;
    inFile.open(DICTIONARY_FILE_NAME);

    string str;
    while (getline(inFile, str))
    {
        str = str.erase(str.length()-1);
        this->input.push_back(str);
    }

    inFile.close();
}

    unordered_set<string> DictionaryFileReader::getValidWords()
{
    this->readFile();
    unordered_set<string> words;
    for (size_t index = 0; index < this->input.size(); index++)
    {
        words.insert(this->input[index]);
    }
    return words;
}
}
