// program to find the unique nunber in an array where each other element occurs 3 times

#include<iostream>
using namespace std;

int findUniqueNo(int *arr, int size)
{
    int temp[64] = {0};

    // extract the bits of all the numbers into a temp array
    for(int j = 0; j < size; j++)
    {
        int i = 0;
        int number = arr[j];
        while(number>0)
        {
            temp[i] += (number&1);
            i++;
            number = number >> 1; 
        }
    }

    // take mod 3 of the array
    int power = 1;
    int ans=0;
    for(int i = 0; i < 64; i++)
    {
        temp[i] %= 3;      
        ans += temp[i]*power;
        power = power<<2;
    }
    return ans;    
}

int main()
{
    int arr[] = {1,1,1,2,2,2,3,4,4,4,5,5,5,6,6,6,7,7,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = findUniqueNo(arr, size);
    cout<<"The unique number is "<<result<<endl; 
    return 0;
}