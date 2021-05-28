// Defining a linked list

/*
 * Ways to define a linked list's NODE:
 * 1) using a structure (struct)
 * 2) using a class
 * it's always better to define it using a class since you get adding class functionalities!
 *
 * But, what about ways to define the entire LINKED LIST:
 * 1) OBJECT ORIENTED: Make a linked list class and add all the functions to it like insert, delete etc.
 *      But this is a waste, since STL has already implemented it! It has to be followed generally when all the functions have to be implemented.
 * 2) PROCEDURE ORIENTED: Make a node class/structure to represent a node and make functions for all other operations. Call these functions whenever need be.
 *      This may be used for better understanding or in interviews when a specific operation has to be inplemented, but try to use Object oriented STL if possible.
 */


// A linked list node using structure
/*

struct Node
{
    int data;
    struct Node *next;
};

 */

// A linked list node using class
class node {
public:
    int data;
    node *next;
};