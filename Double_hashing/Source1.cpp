#include"Header.h"

//first hash function to create hash value
int HashTable::HashFunction(int key, int size)
{
    int value = key %size;
    int doubleValue = (1 + key) % size - 2;

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[value].key == 0)
        {
            return value;
        }

        else
        {
            value = HashFunction2(key,doubleValue);
        }
    }
}

//second hash function to create 2nd hash value
int HashTable::HashFunction2(int value, int doubleValue)
{
    int newValue = (value + doubleValue) % list.size();

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[newValue].key == 0)
        {
            return newValue;
        }
        else
        {
            newValue = (value + newValue) % list.size();
        }
    }
}


void HashTable::Insert(int k, string f)
{
    item.key = k;
    item.fruit = f;

    if (item.key != 0)
    {
        int hashValue = HashFunction(k, list.size());

        list[hashValue] = item;
     
        if (list.size() / 2 == countItems())
        {
            list.resize(list.size() * 2);
            ReHash();
        }

        count = 0;
    }
}


void HashTable::PrintTable(ofstream& fout)
{
    for (auto i : list)
    {
        cout << "[" << i.key << ", " << i.fruit << ", " << i.mark << "]" << endl;
        fout << "[" << i.key << ", " << i.fruit << ", " << i.mark << "]" << endl;
    }
}


void HashTable::ReHash()
{
    for (int i = 0; i < list.size(); ++i)
    {
        Insert(list[i].key, list[i].fruit);
        list[i].key = 0;
        list[i].fruit = "";
    }
}


string HashTable::Find(int k)
{
    int value = k % list.size();
    int doubleValue = (1 + k) % list.size() - 2;

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[value].key == k && list[value].mark == 0)
        {
            return list[value].fruit;
        }

        else
        {
            value = NewHashFunction(k, doubleValue);
        }
    }

    return "item not found";
}


int HashTable::countItems()
{
    for (auto i : list)
    {
        if (i.key != 0)
        {
            count++;
        }
    }
    return count;
}


void HashTable::Delete(int k)
{
    int value = k % list.size();
    int doubleValue = (1 + k) % list.size() - 2;

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[value].key == k)
        {
            list[value].mark = 1;
        }

        else
        {
            value = NewHashFunction(k,doubleValue);
        }
    }
}

//creates new unique has value to avoid collision
int HashTable::NewHashFunction(int value, int doubleValue)
{
    int newValue = (value + doubleValue) % list.size();

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[newValue].key == value)
        {
            return newValue;
        }
        else
        {
            newValue = (value + newValue) % list.size();
        }
    }
}