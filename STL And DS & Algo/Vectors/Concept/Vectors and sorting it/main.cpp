#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>

using namespace std;

//program to input a vector and print it normally and in sorted way

int main(){
    //create a vector v
    vector<int> v;
    //input the size of vector
    cout<<"Input the size of the vector:";
    int size;
    cin>>size;

    //input the elements of the vector
    cout<<"Enter the elements of the vector i.e Dynamic Array:";

    //We'll use loop instead of iterators

    int input;
    for(int i=0; i<size; i++){
        cin>>input;
        v.push_back(input);
    }

    //printing the vector using loops
    cout<<"Unsorted Vector: ";
    for(int i=0; i<size; i++){
        cout<<v[i];
        cout<<" ";
    }
    cout<<"\n";

    //function call from algorithm to sort the array
    sort(v.begin(),v.end());

    //printing the sorted vector
    cout<<"Sorted Vector: ";
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";

    return 0;
}