#include"Header.h"

//insert elements to heap
void Heap::Insert(int num)
{
    cout << "after inserting:" << num << "\n";
    heap.push_back(num);
    MakeHeap(heap, 0);
    Print();
    cout << "\n\n";
}

//prints heap
void Heap::Print()
{
    for (auto i : heap)
    {
        cout << i << " ";
    }
}

Heap::Heap()
{
    ifstream fin;
    int num;
    fin.open("Text.txt");

    cout << "Inserting Elements to heap" << endl;

    while (!fin.eof())
    {
        fin >> num;
        Insert(num);
    }
    
    cout << "\n";

    cout << "Deleting Elements from heap" << endl;

    while (!heap.empty())
    {
        DeleteMin();
    }
}

//creates heap and makes sure that min value is on top of heap
void Heap::MakeHeap(vector<int>& a, int n)
{
    int parent = n;
    int leftC = 2 * n + 1;
    int rightC = 2 * n + 2;

    if (n >= a.size()) { return; }

    MakeHeap(a, leftC);
    MakeHeap(a, rightC);

    if (leftC < a.size())
    {
      if (a[parent] > a[leftC])
        {
            swap(a[parent], a[leftC]);
        }
    }

    if (rightC < a.size())
    {
        if (a[parent] > a[rightC])
        {
            swap(a[parent], a[rightC]);
        }
    }
}

//deletes min elements which is top of heap
void Heap::DeleteMin()
{
    cout << "after deleting: "<< heap[0] << "\n";
    heap.erase(heap.begin());
    MakeHeap(heap, 0);
    Print();
    cout << "\n\n";
}