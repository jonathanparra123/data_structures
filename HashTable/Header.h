#include<iostream>
#include<vector>
#include <string>
#include<fstream>

using namespace std;

//entity of data 
struct  node
{
    int key;
    int mark;
    string fruit;
};

// Hash table class
class HashTable
{
private:
    node item;
    vector<node> list;
    int tableSize;
    int count;
    

public:
    HashTable() { list.resize(10); };

    int HashFunction(int key, int tablesize);

    void Insert(int key, string fruit);

    void PrintTable(ofstream& fout);

    string Find(int key);

    void ReHash();

    int countItems();

    void Delete(int key);

};