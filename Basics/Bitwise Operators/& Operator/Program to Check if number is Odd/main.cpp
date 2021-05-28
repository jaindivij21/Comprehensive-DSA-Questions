#include <iostream> 
using namespace std;

int main() 
{ 
    int x;
    cout<<"Enter the number>";
    cin>>x;

    (x & 1) ? printf("Odd") : printf("Even"); 
    return 0; 
} 