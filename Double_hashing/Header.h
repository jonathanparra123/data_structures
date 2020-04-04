#include<iostream>
#include<vector>
#include <string>
#include<fstream>

using namespace std;


struct  node
{
    int key;
    int mark;
    string fruit;
};


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

    int HashFunction2(int value, int newValue);

    int NewHashFunction(int value, int newValue);

    void Insert(int key, string fruit);

    void PrintTable(ofstream& fout);

    string Find(int key);

    void ReHash();

    int countItems();

    void Delete(int key);

};