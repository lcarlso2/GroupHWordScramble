#include "SettingsFileWriter.h"

namespace io {

SettingsFileWriter::SettingsFileWriter()
{
    //ctor
}

SettingsFileWriter::~SettingsFileWriter()
{
    //dtor
}

void SettingsFileWriter::writeSettingsToFile(const int numberOfLetters, const int timer) {
    ofstream myFile;
    myFile.open("settings");

    myFile << to_string(numberOfLetters) << "," << to_string(timer) << endl;


    myFile.close();
}

}
