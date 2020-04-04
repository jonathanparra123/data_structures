#include<iostream>
#include<fstream>
#include<string>
#include "Header.h"
using namespace std;

//loads list of numbers
binarySearchTree::binarySearchTree()
{
    ifstream fin("nums.txt");
    int number;

    while (!fin.eof())
    {
        fin >> number;
        ListOfNum.push_back(number);
    }
}

//builds tree structure
node* binarySearchTree::MakeTree(node* n, int number)
{
    if (n == nullptr) { n = new node(number); }

    if (n->num < number)
    {
        n->right = MakeTree(n->right, number);
    }
    else if (n->num > number)
    {
        n->left = MakeTree(n->left, number);
    };

    return n;
}

void binarySearchTree::play()
{
    int initialNum = ListOfNum[0];

    root = new node(initialNum);

    height = 0;

    for (int i = 0; i < ListOfNum.size(); ++i)
    {
        initialNum = ListOfNum[i];
        MakeTree(root, initialNum);

        PrintTree(root, height);
        cout << "height of tree: " << height << endl;

        height = 0;
    }
}

//prints out entire tree with each number added and recurvesly calculates level of trees
void binarySearchTree::PrintTree(node* n, int level)
{
    if (n == nullptr) { return; }
    
    if (height < level) {height = level;}
   
    PrintTree(n->right, level+1);
   
   for (int j = 0; j < level; j++)
    {
        cout << "  ";
    }
   
    cout << n->num << endl;

    PrintTree(n->left, level+1);
}


