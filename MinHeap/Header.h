#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

//Class for Min Heap
class Heap
{
private:
    vector<int> heap;
    
public:

    Heap();

    void Insert(int num);

    void Print();

    void MakeHeap(vector<int>& a, int n);

    void DeleteMin();

};