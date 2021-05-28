// Compress the string i.e. aaabbccds --> a3b2c2d1s1
#include<iostream>
#include<cstring>

using namespace std;

int main() {
    // input the string
    string a;
    cin >> a;

    int count = 0;
    for (int i = 0; i < a.length();) {
        // print the element 
        cout<<a[i];
        char temp = a[i];
        // cal the count
        while(a[i] == temp)
        {
            count++;
            i++;
        }
        // print its count 
        cout<<count;
        count = 0;
    }

    return 0;
}