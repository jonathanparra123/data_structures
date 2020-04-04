#include<iostream>
#include<vector>
using namespace std;

//node for tree structure
struct node
{
    string word;

    node* right;//siblings
    node* left;//child

    node(string w) { word = w; right = nullptr, left = nullptr;}
};

//class that holds structures
class binarySearchTree
{
public:
    binarySearchTree();
    void setWords(string setFirst, string setSecond);

    void FindWord(string startingW);
    bool checkDict(string word, vector<string> dict, int high, int low);

    node* MakeTree(node* n, string currentW);
    void play();

    bool IsNewWord(string check);

    void PrintTree(node* tree);
    bool PrintLadder(node* n);


private:
    vector<string> dictionary;
    vector<string> smallerDictionary;
    vector<string> usedWords;
    vector<string> flipLadder;

    string startingWord;
    string endingWord;

    node* root;

    bool wordFound;
};
