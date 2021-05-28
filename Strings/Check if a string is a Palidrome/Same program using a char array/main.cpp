#include<iostream>
#include<cstring>
using namespace std;

int main()
{

    char arr[100];
    cin.getline(arr, 100);

    // if palindrome
    int i = 0;
    int j = strlen(arr) - 1;
    int flag = 1;
    while(arr[i]<arr[j]){
        if(i!=j)
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }

    if(flag == 0)
        cout<<"Not a palindrome"<<endl;
    else
        cout<<"Palindrome"<<endl;
    return 0;
}