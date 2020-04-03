#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<queue>
using namespace std;

//game class
class game
{
public:
    queue<vector<string>> ladders;
    
    void ChangeWord(vector<string> firstWord);
    vector<string> storeWords;
    vector<string> usedWords;

    bool CheckSize(string first, string second);
    bool binarySearchDict(vector<string> vector, int low, int high, string target);
    bool isNew(vector<string> old, string target);

    void play(string startingWord, string endingWord);

    vector<string> dict();

private:

    vector<string> word = dict();
    vector<string> smallerDict;
    bool wordFound;
};




