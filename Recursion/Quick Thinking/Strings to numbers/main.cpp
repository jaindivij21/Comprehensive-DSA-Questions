// Convert String numbers int *int* format
// USE RECURSION
// Ex. "2048" - 2048

#include<iostream>
#include<cstring>

using namespace std;

int stringtoInt(char *a, int n) {
    // base case
    if (n == 0)  // length fo string is 0
        return 0;
    else {
        // get the last number
        int digit = a[n - 1] - '0';
        // recursive call to the next
        int smallNumber = stringtoInt(a, n - 1);

        return smallNumber * 10 + digit;
    }
}

int main() {
    // limit the string lenght to 100 characters
    char num[100];

    // input
    cout << "Enter the string of numbers" << endl;
    cin.get(num, 100);

    //  main
    cout << stringtoInt(num, strlen(num)) << endl;

    return 0;
}