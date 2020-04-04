#include"Header.h"

//creates hash value
int HashTable::HashFunction(int key, int size)
{
    int value = key%size;

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[value].key == 0)
        {
            return value;
        }

        else
        {
            value/=2;
        }
    }
}

//when inserting an item, it will check size of hash table and resize
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

//looks for item using hash value
string HashTable::Find(int k)
{
    int value = k % list.size();

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[value].key == k && list[value].mark == 0)
        {
            return list[value].fruit;
        }

        else
        {
            value /= 2;
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

//deletes items using hash values
void HashTable::Delete(int k)
{
    int value = k % list.size();

    for (int i = 0; i < list.size(); ++i)
    {
        if (list[value].key == k)
        {
            list[value].mark = 1;
        }

        else
        {
            value /= 2;
        }
    }
}