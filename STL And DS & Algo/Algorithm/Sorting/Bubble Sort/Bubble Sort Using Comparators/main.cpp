// Using comaprators and passing functions as parameters
// Bubble Sort

#include<iostream>

using namespace std;

// for ascending order
bool comparatorFunction1(int a, int b) {
    cout << "Comparing " << a << " with " << b << endl;
    return a > b;
}

// for decending order
bool comparatorFunction2(int a, int b) {
    cout << "Comparing " << a << " with " << b << endl;
    return a < b;
}

//bubble sort
void bubbleSort(int arr[], int size, int choice, bool (&cmp1)(int a, int b), bool (&cmp2)(int a, int b)) {
    if (choice == 1) {
        for (int i = 1; i <= size-1; i++) {
            for (int j = 0; j <= size - i - 1; j++) {
                if (cmp1(arr[j], arr[j + 1]))
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
    if (choice == 2) {
        for (int i = 1; i <= size-1; i++) {
            for (int j = 0; j <= size - i - 1; j++) {
                if (cmp2(arr[j], arr[j + 1]))
                    swap(arr[j], arr[j + 1]);
            }
        }
    }
}


int main() {
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    int arr[size];
    cout << "Enter the array" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];
    int choice;
    cout << "Current Array" << endl;
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    cout << "Enter the choice (1-Asc/2-Des)" << endl;
    cin >> choice;
    bubbleSort(arr, size, choice, comparatorFunction1, comparatorFunction2);
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    return 0;

}