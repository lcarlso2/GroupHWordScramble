#include "OutputFormatter.h"

namespace view
{
OutputFormatter::OutputFormatter()
{
    //ctor
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

string OutputFormatter::formatScores(vector<PlayerScore> scores)
{
    stringstream builder;
    builder << left << setw(NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_SCORES) << "NAME" << left
            << setw(NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_SCORES) << "SCORE" << right << setw(DEFAULT_COLUMN_COUNT) << "TIME" << endl;
    for (auto& currentScore : scores)
    {
        builder << left << setw(NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_SCORES) << currentScore.getName() << left
                << setw(NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_SCORES) << currentScore.getScore() << right << setw(DEFAULT_COLUMN_COUNT) << toTime(currentScore.getTime()) << endl;
    }

    return builder.str();
}

string OutputFormatter::formatRemainingWords(const int totalWords, const int wordsGuessed)
{
    return to_string(wordsGuessed) + "/" + to_string(totalWords);
}

string OutputFormatter::formatWordsToDisplayDuringGame(map<string, string> words, map<string, int> guessedWords)
{
    stringstream builder;

    int columnCount = DEFAULT_COLUMN_COUNT;
    for (auto& word : words)
    {
        if (guessedWords.count(word.first) != WORD_IS_NOT_PRESENT)
        {
            string guessedWordAndPoints = word.first + "-" + to_string(guessedWords[word.first]) + " points";
            builder << left << setw(NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_DISPLAYING_WORDS) << guessedWordAndPoints;
        }
        else
        {
            builder << left << setw(NUMBER_OF_SPACES_BETWEEN_COLUMNS_FOR_DISPLAYING_WORDS) << word.second;
        }

        if (columnCount == MAX_COLUMN_COUNT)
        {
            builder << endl;
            columnCount = DEFAULT_COLUMN_COUNT;
        }
        columnCount++;
    }

    return builder.str();
}


string OutputFormatter::formatBonusWordPointsForDisplay(const int points)
{
    stringstream builder;

    builder << "Bonus word! You receive " << points << " points! 100 more points than normal!" << endl;

    return builder.str();
}


}
