# data_structures
-Different types of data structures such as Hash tables, trees, and linked lists.

-Using C++ as the main language.

-Every folder has a different type of data structure.

*******************************************************************************

word_ladder_BST is a Word Ladder program using a txt file for the dictionary.
The program uses a binary search tree to find assosiated words which then 
builds a ladder from a staring word to an ending word of the same lenght with
each word in the ladder having at least one letter in common with the last word. 

********************************************************************************

BST_Linked_List is similar to word_ladder_BST program but this time it is 
building a binary tree structure with a linked list pointing to two child
nodes. The programs first builds the data struct using a linked list then
it looks for appropriate words to build the ladders. The reason why i build
a binary tree structure is to decrease the run time of the program.

*********************************************************************************

BST_num_recursion deals with numbers instead of words. Everytime a numbers gets
inserted into the tree, it will print out the actual tree structure with each 
number and recursively find the height of the tree each time. This programs 
shows what the binary tree looks like at each iteration with each node having
a right and left child which represent a less or greater number than the parent
node respectively.

*********************************************************************************
