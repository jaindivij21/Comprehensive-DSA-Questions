#include <iostream>
#include <cstring>
using namespace std;

// Program to show the difference bw arrays and strings wrt to pointers

int main(){
    char str[] = "Hello I am Divij";    // since a string is an array of type char
    int arr[] = {1,2,3};

    cout<< arr<< " "<< str<<endl;   // both are arrays but arr gives address and str prints the actual string

//  ### This is done for ease of use of strings
// It happens due to cout** ---> it has been operater overloaded to not print the char's address by default rather print the value
    // to print addresses of both:
    cout<< arr << " " << (void *) str << endl;

    // OR INSTEAD OF THIS
    char *ptr = str;
    cout<<ptr<<endl;

    void *ptr2 = str;
    cout<<ptr2<<endl;

    return 0;
}