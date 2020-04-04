#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;


struct node
{
    int num;
    int level;

    node* right;//siblings
    node* left;//child

    node(int n, int l) { num = n; right = nullptr, left = nullptr; level = l;}
};


class AVLTree
{
public:
    AVLTree();

    node* MakeTree(node* n, int number, int level);
    node* RotateRight(node* n);
    node* RotateLeft(node* n);
    
    void play();
    void PrintTree(node* tree, int level);
    
    int Balance(node* n);
    int Height(node* n);


private:
    vector<int> ListOfNum;
    node* root;
    int height;
};
