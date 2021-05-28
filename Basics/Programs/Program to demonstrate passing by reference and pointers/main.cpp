// C++ program to swap two numbers using 
// pass by reference and pass by pointers.
 
#include <iostream> 
using namespace std;

  
void passbypointer(int* x, int* y) 
{ 
    int z = *x; 
    *x = *y; 
    *y = z; 
} 
  

void passbyreference(int& x, int& y) 
{ 
	int z = x; 
	x = y; 
	y = z; 
} 

int main() 
{ 
	int a = 45, b = 35; 
	cout << "Before Swap\n"; 
	cout << "a = " << a << " b = " << b << "\n"; 

	passbyreference(a, b); 
    passbypointer(&a, &b); 

	cout << "After Swap with pass by reference\n"; 
	cout << "a = " << a << " b = " << b << "\n"; 
} 
