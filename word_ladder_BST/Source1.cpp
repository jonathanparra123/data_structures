#include<iostream>
#include "Header.h"
using namespace std;


//dictionary
vector<string> game::dict()
{
    ifstream fin("dictionary.txt");
    string words;
    vector<string> vectorWords;

    while (!fin.eof())
    {
        getline(fin, words);
        vectorWords.push_back(words);
    }

    return vectorWords;
}


//ladder function
void game::ChangeWord(vector<string> currentLadder)
{
    string nextWord = currentLadder[currentLadder.size() - 1];
    string firstword = currentLadder[currentLadder.size() - 1];

    vector<string> temp = currentLadder;

            for (int i = 0; i < nextWord.size(); ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    nextWord[i] = 'a' + j;

                    if (binarySearchDict(smallerDict,0,smallerDict.size(),nextWord) == true && isNew(usedWords, nextWord) == true)
                    {
                        storeWords.push_back(nextWord);
                        ladders.push(storeWords);
                        storeWords.clear();
                        usedWords.push_back(nextWord);
                    }
                    storeWords = temp; 
                }
                 nextWord = firstword;
            }
}


//check if same size
bool game::CheckSize(string first, string second)
{
    if (first.size() == second.size())
    {
        return true;
    }

    else
    {
        return false;
    }
}


//insert first word
void game::play(string startingWord, string endingWord)
{   
    for (int k = 0; k < word.size(); ++k)
    {
        if (word[k].size() == startingWord.size())
        {
            smallerDict.push_back(word[k]);
        }
    }

    if (binarySearchDict(smallerDict, 0, smallerDict.size(), startingWord) == true && binarySearchDict(smallerDict, 0, smallerDict.size(), endingWord) == true)
    {
        storeWords.push_back(startingWord);
        usedWords.push_back(startingWord);

        while (wordFound == false)
        {
            ChangeWord(storeWords);
            storeWords = ladders.front();
            if (isNew(usedWords, endingWord) == true) {
                ladders.pop();
            }
        }

        vector<string> show;

        while(!ladders.empty())
        {
            show = ladders.front();

            if (show[show.size() - 1] == endingWord)
            {
                for (auto i : show)
                {
                    cout << i << endl;
                }
            }

            ladders.pop();
        }
    }

    else 
    {
        cout << "not ladder found" << endl;
    }
}


//binary search in dictionary
bool game::binarySearchDict(vector<string> vector, int low, int high, string target)
{
    high = high - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (vector[mid] == target)
        {
            return true;
        }

        else if (vector[mid] > target)
        {
            high = mid - 1;
        }

        else if (vector[mid] < target)
        {
            low = mid + 1;
        }

     }

    return false;
}


//search for new word
bool game::isNew(vector<string> old, string target)
{
    for (auto i : old)
    {
        if (i == target)
        {
            wordFound = true;
            return false;
        }
    }

    wordFound = false;
    return true;
}


