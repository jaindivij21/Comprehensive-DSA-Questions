#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//program to use functions to print an array
void printArray(int arr[], int len);

int main() {
    int arr[5];
    cout << "Enter the values of the array" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    int len = (sizeof(arr)) / (sizeof(int));
    printArray(arr, len);
    getch();
    return 0;
}

void printArray(int arr[], int len) {


    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}