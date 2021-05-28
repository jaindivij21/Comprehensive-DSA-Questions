// Hollow Diamond Pattern

/*

 n = 2

  %
 % *
%   *
 % *
  %

 */


#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // rows of upper triangle
    for (int i = 0; i <= n; i++) {
        // spaces in these rows
        for (int j = 0; j < abs(n - i); j++) {
            cout << " ";
        }
        // %  sign
        cout << "%";

        // spaces
        for (int j = 0; j < 2 * i - 1; j++)
            cout << " ";
        if (i != 0)
            cout << "*";
        // next line
        cout << endl;
    }

    // bottom triangle
    for (int i = n; i > 0; i--) {
        // spaces
        for (int j = 0; j < n - i + 1; j++)
            cout << " ";
        // % sign
        cout << "%";

        // spaces
        for (int j = 0; j < 2 * i - 3; j++)
            cout << " ";
        if (i != 1)
            // star
            cout << "*";
        // next line
        cout << endl;
    }
    return 0;
}