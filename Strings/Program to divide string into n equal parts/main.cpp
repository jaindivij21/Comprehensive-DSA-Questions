// Program to divide a string in N equal parts
#include<iostream>
#include<cstring>

using namespace std;

int main() {
    cout << "Enter the string" << endl;
    string str;
    getline(cin, str);
    cout << "Enter number of parts" << endl;
    int n;
    cin >> n;

    int lengthTotal = str.length();
    int lengthOfEach = (lengthTotal / n);

    string r;
    for (int i = 0; str[i] != '\0'; i += (lengthOfEach)) {
        r = str.substr(i, lengthOfEach);
        cout << r << endl;
    }
    return 0;
}
