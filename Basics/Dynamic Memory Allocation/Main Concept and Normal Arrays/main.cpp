// Programt o describe Dynamic Mmeory Allocation

#include<iostream>
using namespace std;

int main()
{
    // STATIC MEMORY ALLOCATION
    
    // Done by the compiler during compile time - fast but fixed
    // Both Allocation and Deallocation at the end of function call is done by compiler
   
    int a = 10;

    int b[100] = {0};
    cout<<sizeof(b)<<end;   // prints the size of entire array
    cout<<b<<endl;  // this prints the starting address of array 'b'. This value comes from the symbol table
    // here b cannot be overwritten
   
   
    // DYNAMIC MEMORY ALLOCATION

    // Done during runtime by the program and not the compiler
    // Both allocation and deallocation needs to be done by the user in the program properly
    // other wise can lead to memory leaks. Slow but efficient and not fixed
    // Makes use of heap memory (larger) instead of the smaller satck memory
    // pointers are made in stack memory which point to the larger memory allocaations like arrays in the heap memory

    int *x = new int;   // dynamic basket that stores an int
    // *NEW* keyword is used for memory allocation 
    // *DELETE* keyword is used for memory deallocaiton

    // remember to reassign dynnamic memory portion to another pointer,
    // you must deallocate it first i.e. delete it, before you can reassign it

    int n;
    cin>>n;
    int *a = new int[n];    // Array/Chunk of memory from heap memory assigned to a pointer 'a' in stack memory
    cout<<sizeof(a)<<endl;  // this prints the size of pointer i.e 4 bytes in stack mem and not the size of full array
    cout<<a<<endl;  // Similar to static, this prints the first loc of the array
    // here a can be overwritten after dedallocation

    // No change
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    
    // malloc and calloc are also used for allocation
    // free is also used for deallocation

    return 0;
}