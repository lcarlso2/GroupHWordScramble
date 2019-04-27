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

    myFile << to_string(numberOfLetters) << COMMA << to_string(timer) << endl;


    myFile.close();
}

void TextFileWriter::writeScoresToFile(HighScoreBoard scoreBoard)
{
    ofstream myFile;
    myFile.open(HIGH_SCORE_FILE_NAME);

    for(PlayerScore current : scoreBoard.getScores())
    {
        myFile << current.getName() << COMMA << to_string(current.getScore()) << COMMA << to_string(current.getTime()) << endl;
    }

    myFile.close();


}

}
