// Write 2 functions to print first N numbers in increasing and decreasing order respectively using recursion

#include<iostream>

using namespace std;

void increasing(int n) {
    // base case
    if(n == 0)
        return;
    else
    {
        // assuming inc(n-1) sub problem is correct & this is also our realtion
        increasing(n-1);
        cout<<n<<" ";
    }

}

void decreasing(int n) {
    // base case
    if(n == 0)
        return;
    else
    {
        // assuming dec(n-1) sub problem is correct & this is also our realtion
        cout<<n<<" ";
        decreasing(n-1);
    }
}

int main() {
    // enter the number n
    int n;
    cin >> n;

    increasing(n);
    cout<<endl;
    decreasing(n);

    return 0;
}