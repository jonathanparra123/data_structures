#include<iostream>
#include<vector>
using namespace std;

//node of parent
struct node
{
    int num;

    node* right;//siblings
    node* left;//child

    node(int n) { num = n; right = nullptr, left = nullptr; }
};

//binary tree class
class binarySearchTree
{
public:
    binarySearchTree();

    node* MakeTree(node* n, int number);
    void play();
    void PrintTree(node* tree, int level);

private:
    vector<int> ListOfNum;
    node* root;
    int height;
};
