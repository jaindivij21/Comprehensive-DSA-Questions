// program to add 2 numbers in 2 arrays

#include<iostream>
using namespace std;

// main function to add the arrays
void addArrays(int arr1[], int arr2[], int arr3[], int n1, int n2, int n3)
{
    int carry = 0;
    int count = 0;
    int temp = 0;
    // for the entire len of arr3 which is always one more than max(n1, n2)
    for(int i = n3 - 1; i >= 0; i--)
    {
        // cal the value of temp i.e sum of those particular digits
        if( n1 <= 0 && n2 <= 0)
            temp = carry;
        else if(n1<=0 && n2 > 0)
            temp = arr2[n2-1]+carry;
        else if (n2 <= 0 && n1 > 0)
            temp = arr1[n1-1]+carry;
        else
            temp = (arr1[n1-1]+arr2[n2-1])+carry;
        arr3[i] = temp%10;
        carry = temp/10;
        n1--;
        n2--;
    }
}

int main() {
    // input the both arrays
    int n1, n2;
    cin >> n1;
    int arr1[n1];
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];
    cin >> n2;
    int arr2[n2];
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    // make a third array w length one greater than the length of bigger array
    int n3 = n1 >= n2 ? n1 + 1 : n2 + 1;
    int arr3[n3];
    addArrays(arr1, arr2, arr3, n1, n2, n3);

    // print the arr3 i.e the sum arrays
    bool flag = false;
    for (int i = 0; i < n3; i++) {
        if (arr3[i] != 0)
            flag = true;
        if (flag)
            cout << arr3[i] << ", ";
    }
    cout << "END" << endl;
}