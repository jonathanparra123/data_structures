#include<iostream>
#include"Header.h";
using namespace std;

int main()
{
    ///////////change words
    string first;
    string second;

    cout << "first word: ";
        cin >> first;
    cout << "second word: ";
        cin >> second;

    ///////////game
    game display;

    if (display.CheckSize(first, second) == true)
    {  
        cout << "Wordladder from " << first << " to " << second << "\n"; 
        display.play(first, second);
    }

    else
    {
        cout << "needs to be same size or not in dictionary" << endl;
        return 0;
    }
    
}