#include "Utils.h"

#include <iostream>
#include <unordered_set>

#include "DictionaryFileReader.h"
using namespace io;
using namespace std;
const string toTime(const int value)
{
    string minutes;
    string seconds;
    string time;
    minutes = to_string(value / 60);
    seconds = to_string(value % 60);

    if (seconds == "0")
    {
        seconds = "00";
    }
    else if (seconds.length() == 1)
    {
        seconds = "0" + seconds;
    }
    return minutes + ":" + seconds;
}

vector<string> permute(string str, string out, vector<string> words)
{

    if (str.size() == 0)
    {
        words.push_back(out);
        return words;
    }

    for (int i = 0; i < str.size(); i++)
    {
        permute(str.substr(1), out + str[0], words);
        rotate(str.begin(), str.begin() + 1, str.end());
    }
    return words;
}

void combinationEasy(string input, int pos, string r)
{
    cout << r << endl;

    for (int i = pos; i < input.length(); i++)
    {
        //if (i != pos && input[i] == input[i-1]){
        //  continue;
        // }
        r.push_back(input[i]);
        combinationEasy(input, i +1, r);
        r.erase(r.size()-1);
    }
}

void combinationEasy(string input)
{
    string r;
    sort(input.begin(), input.end());
    combinationEasy(input, 0, r);
}


// The main recursive method
// to print all possible
// strings of length k
unordered_set<string> printAllKLengthRec(string input, string prefix, int n, int k, unordered_set<string> words)
{

    // Base case: k is 0,
    // print prefix
    if (k == 0)
    {
        //  cout << (prefix) << endl;
        return words;
    }

    // One by one add all characters
    // from set and recursively
    // call for k equals to k-1
    for (int i = 0; i < n; i++)
    {
        string newPrefix;
        // Next character of input added
        if (prefix.find(input[i]) == string::npos ||  (input[i] == input[i+1]))
        {
            cout << "TEST----   current   " << input[i] << "    next    " << input[i+1] << endl;
            //  cout << prefix << endl;
            //  cout << "STUFF HAPPENs    "<< endl;
            newPrefix = prefix + input[i];
            //printAllKLengthRec(set, newPrefix, n, k - 1, words);
        }
        else
        {
            newPrefix = prefix;
        }
        // cout << prefix << endl;
        words.insert(newPrefix);
        // k is decreased, because
        // we have added a new character
        words = printAllKLengthRec(input, newPrefix, n, k - 1, words);
    }
    return words;

}

void printAllKLength(string input, int k,int n)
{
    unordered_set<string> test;
    sort(input.begin(), input.end());
    unordered_set<string> words = printAllKLengthRec(input, "", n, k, test);

    for (auto& current : words)
    {
        cout << current << endl;
    }

}


bool isPossible(string word, string letters)
{
    for (size_t index = 0; index < word.length(); index ++)
    {
        bool result = false;
        for (size_t letterIndex = 0; letterIndex < letters.length(); letterIndex++){
            if (word[index] == letters[letterIndex] && (count(word.begin(), word.end(), word[index]) <= count(letters.begin(), letters.end(), letters[letterIndex]) )){
                result = true;
            }
        }
        if (result == false){
            return false;
        }
    }
    return true;

}

unordered_set<string> findAllValidWords(string letters)
{
    DictionaryFileReader reader;
    unordered_set<string> dictionary = reader.getValidWords();
    unordered_set<string> result;
    for (auto& word : dictionary)
    {
        if (word.length() >= 3) {
        if (isPossible(word, letters))
        {
            result.insert(word);
        }
        }
    }
    return result;


}

