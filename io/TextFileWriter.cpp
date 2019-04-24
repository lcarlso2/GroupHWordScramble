#include "TextFileWriter.h"

namespace io
{

TextFileWriter::TextFileWriter()
{
    //ctor
}

TextFileWriter::~TextFileWriter()
{
    //dtor
}

void TextFileWriter::writeSettingsToFile(const int numberOfLetters, const int timer)
{
    ofstream myFile;
    myFile.open(SETTINGS_FILE_NAME);

    myFile << to_string(numberOfLetters) << "," << to_string(timer) << endl;


    myFile.close();
}

}
