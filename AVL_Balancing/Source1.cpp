#include "Header.h"

//loads numbers to vector
AVLTree::AVLTree()
{
    ifstream fin("nums.txt");
    int number;

    while (!fin.eof())
    {
        fin >> number;
        ListOfNum.push_back(number);
    }
}


//builds tree and at the same time checks any balancing issues
node* AVLTree::MakeTree(node* n, int number, int level)
{
    if (n == nullptr) { n = new node(number, level); }

    if (n->num < number)
    {
        n->right = MakeTree(n->right, number, level+1);
    }
    else if (n->num > number)
    {
        n->left = MakeTree(n->left, number, level+1);
    };

    n->level = max(Height(n->left), Height(n->right)) + 1;
    
    int levels = Balance(n);

    if (levels > 1 && number < n->left->num)
    {
        return RotateRight(n);
    }

    if (levels < -1 && number > n->right->num)
    {
        return RotateLeft(n);
    }

    if (levels > 1 && number > n->left->num)
    {
        n->left = RotateLeft(n->left);
        return RotateRight(n);
    }

    if (levels < -1 && number < n->right->num)
    {
        n->right = RotateRight(n->right);
        return RotateLeft(n);
    }

    return n;
}


//rotates node right adjusting and balancing tree
node* AVLTree::RotateRight(node* n)
{
    node* temp1 = n->left;
    node* temp2 = temp1 ->right;

    temp1->right = n;
    n->left = temp2;

    n->level = max(Height(n->left), Height(n->right)) + 1;
    temp1->level = max(Height(temp1->left), n->level) + 1;

    return temp1;
}

//rotates node left adjusting and balancing tree
node* AVLTree::RotateLeft(node* n)
{
    node* temp1 = n->right;
    node* temp2 = temp1->left;

    temp1->left = n;
    n->right = temp2;

    n->level = max(Height(n->left), Height(n->right)) + 1;
    temp1->level = max(Height(temp1->right), n->level) + 1;

    return temp1;
}


void AVLTree::play()
{
    int initialNum = ListOfNum[0];

    root = new node(initialNum, 0);

    height = 0;

    for (int i = 0; i < ListOfNum.size()-1; ++i)
    {
        initialNum = ListOfNum[i];
        MakeTree(root, initialNum, 0);

        PrintTree(root, height);
        cout << "after in inserting: " << ListOfNum[i] << endl;

        height = 0;
    }
}


void AVLTree::PrintTree(node* n, int level)
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

//checks to see if the tree is balanced by checking the children nodes
int AVLTree::Balance(node* n)
{
    if(n == nullptr)
    {
        return 0;
    }

    return Height(n->left) - Height(n->right);
}


int AVLTree::Height(node* n)
{
    if (n == nullptr)
    {
        return 0;
    }
    return n->level;
}
