#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"
using namespace std;

//load the dictionary into vector
binarySearchTree::binarySearchTree()
{
    ifstream fin("dictionary.txt");
    string words;

    while (!fin.eof())
    {
        fin >> words;
        dictionary.push_back(words);       
    }
}

//function to decrease running time by making a sub dictionary of words with same length only
void binarySearchTree::setWords(string setFirst, string setSecond)
{
    startingWord = setFirst;
    endingWord = setSecond;

    for (auto i : dictionary)
    {
        if (i.length() == startingWord.length())
        {
            smallerDictionary.push_back(i);
        }
    }

    play();
}


void binarySearchTree::FindWord(string startingW)
{
    string changeW = startingW;

    for (int i = 0; i < changeW.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            changeW[i] = 'a' + j;

            if (checkDict(changeW, smallerDictionary, smallerDictionary.size(), 0) == true && IsNewWord(changeW) == true)
            {
                usedWords.push_back(changeW);
            }
        }
        changeW = startingW;
    }
}


bool binarySearchTree::checkDict(string word, vector<string> dict, int high, int low)
{
    high = high - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (dict[mid] == word)
        {
            return true;
        }

        else if (dict[mid] > word)
        {
            high = mid - 1;
        }

        else if (dict[mid] < word)
        {
            low = mid + 1;
        }
    }
    return false;
}

//constructing a binary seacrch tree
node* binarySearchTree::MakeTree(node* n, string currentW)
{
    if (n == nullptr) { n = new node(currentW); }
    
    if (n->word < currentW)
   {
       n ->right = MakeTree(n->right, currentW);
   }
    else if (n->word > currentW) 
    {
       n ->left = MakeTree(n->left, currentW);
    };

    return n;
}


void binarySearchTree::play()
{
    root = new node(startingWord);

    usedWords.push_back(startingWord);

    wordFound = false;

    for (int i = 0; i < usedWords.size(); ++i)
    {
        if (wordFound == false)
        {
            startingWord = usedWords[i];

            FindWord(startingWord);

            MakeTree(root, startingWord);

            if (startingWord == endingWord) { wordFound = true; }
        }
     }

    PrintTree(root);

    cout << "\nWord ladder: " << endl;

    PrintLadder(root);

    for (int i = flipLadder.size() - 1; i >= 0; --i)
    {
        cout << flipLadder[i] << endl;
    }
}

//prints out entire tree
void binarySearchTree::PrintTree(node* n)
{
        if (n == nullptr) { return; }

        cout << n->word << endl;

        PrintTree(n->left);
        PrintTree(n->right);   
}

bool binarySearchTree::PrintLadder(node* n)
{
    bool result;

    if (n == nullptr) { return false; }

    if (n->word == endingWord)
    {
        flipLadder.push_back(n->word);

        return true;
    }

    result = PrintLadder(n->left) || PrintLadder(n->right);

    if (result == true)
    {
        flipLadder.push_back(n->word);
    }

    return result;
}


bool binarySearchTree::IsNewWord(string check)
{
    for (auto i : usedWords)
    {
        if (i == check)
        {
            return false;
        }
    }
    return true;
}

