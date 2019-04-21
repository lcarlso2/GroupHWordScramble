#include "SettingsFileWriter.h"

namespace io
{

SettingsFileWriter::SettingsFileWriter()
{
    //ctor
}

SettingsFileWriter::~SettingsFileWriter()
{
    //dtor
}

void SettingsFileWriter::writeSettingsToFile(const int numberOfLetters, const int timer)
{
    ofstream myFile;
    myFile.open(SETTINGS_FILE_NAME);

    myFile << to_string(numberOfLetters) << "," << to_string(timer) << endl;


    myFile.close();
}

}
