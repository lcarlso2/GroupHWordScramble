#include "OutputFormatter.h"

#include <iostream>
namespace view {
OutputFormatter::OutputFormatter()
{
    //ctor
}

OutputFormatter::~OutputFormatter()
{
    //dtor
}

string OutputFormatter::formatWords(map<string, int> words) {
    stringstream builder;
    for (auto& currentWord : words) {
        builder << "Word: " << currentWord.first << "-" << currentWord.second << " point(s)" << endl;
    }

    return builder.str();
}

}
