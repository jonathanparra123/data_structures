#include"Header.h"


int main()
{
    ofstream fout;

    fout.open("output.txt");

    HashTable hash;

    hash.Insert(4218, "apricots");
    hash.Insert(4011, "banana");
    hash.Insert(4885, "basil");
    hash.Insert(4525, "asparagus");

    cout << "initial list:\n";
    fout << "initial list:\n";
    hash.PrintTable(fout);

    ////5th insert
    hash.Insert(4229, "banana burro");

    cout << "\n";
    cout << "after 5th insert:\n";
    fout << "\n";
    fout << "after 5th insert:\n";
    hash.PrintTable(fout);

    ////9th insert
    hash.Insert(4514, "alfalfa sprouts");
    hash.Insert(4131, "apple fuji");
    hash.Insert(4133, "apple gala");
    hash.Insert(4017, "apple granny smith");

    cout << "\n";
    cout << "after 9th insert:\n";
    fout << "\n";
    fout << "after 9th insert:\n";
    hash.PrintTable(fout);

    ///10th insert
    hash.Insert(4225, "avocado large hass");

    cout << "\n";
    cout << "after 10th insert:\n";
    fout << "\n";
    fout << "after 10th insert:\n";
    hash.PrintTable(fout);

    ///20th insert
    hash.Insert(4227, "avocado small");
    hash.Insert(4234, "banana leaf");
    hash.Insert(4232, "banana baby");
    hash.Insert(4235, "banana macho");
    hash.Insert(4536, "bean sprouts");
    hash.Insert(3176, "beans black");
    hash.Insert(3196, "beans black eye");
    hash.Insert(3174, "beans garbanzo");
    hash.Insert(4066, "beans green");
    hash.Insert(3175, "beans haba dry");

    cout << "\n";
    cout << "after 20th insert:\n";
    fout << "\n";
    fout << "after 20th insert:\n";
    hash.PrintTable(fout);

    ///find
    cout << "\n";
    cout << "find item 4234: " << "\n" << hash.Find(4234) << "\n\n";
    cout << "find item 3175: " << "\n" << hash.Find(3175) << "\n\n";
    cout << "find item 4885: " << "\n" << hash.Find(4885) << "\n";
    fout << "\n";
    fout << "find item 4234: " << "\n" << hash.Find(4234) << "\n\n";
    fout << "find item 3175: " << "\n" << hash.Find(3175) << "\n\n";
    fout << "find item 4885: " << "\n" << hash.Find(4885) << "\n";

    ///delete
    cout << "\n";
    cout << "deleting item 3196: beans black eye\n";
    cout << "deleting item 4234: banana leaf\n";
    cout << "deleting item 4235: banana macho\n";
    fout << "\n";
    fout << "deleting item 3196: beans black eye\n";
    fout << "deleting item 4234: banana leaf\n";
    fout << "deleting item 4235: banana macho\n";

    hash.Delete(3196);
    hash.Delete(4234);
    hash.Delete(4235);

    cout << "\n";
    cout << "finding deleted items:\n";
    cout << hash.Find(3196) << "\n";
    cout << hash.Find(4234) << "\n";
    cout << hash.Find(4235) << "\n";
    fout << "\n";
    fout << "finding deleted items:\n";
    fout << hash.Find(3196) << "\n";
    fout << hash.Find(4234) << "\n";
    fout << hash.Find(4235) << "\n";

    cout << "\n";
    cout << "table after deleted items: *deleted item marked with 1*\n";
    fout << "\n";
    fout << "table after deleted items: *deleted item marked with 1*\n";
    hash.PrintTable(fout);


    return 0;
}