// ad-hoc problem 2D Arrays
// Piyush and magivcal park
// https://www.youtube.com/watch?v=3J1tAsoZ7-g

#include<iostream>

using namespace std;

int magicalPark(char a[][100], int m, int n, int k, int s) {

    int x = s + 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (k >= x)
                return -1;
            else {
                x--;
                if (a[i][j] == '.')
                    x -= 2;
                if (a[i][j] == '*')
                    x += 5;
                if (a[i][j] == '#')
                    break;
            }
        }
        x++;
    }
    x--;
    return x;
}

int main() {
    int m, n, k, s;
    cin >> m >> n >> k >> s;

    char park[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cin >> park[i][j];
    }

    int res = magicalPark(park, m, n, k, s);
    if (res == -1)
        cout << "No" << endl;
    else
        cout << "Yes " << res << endl;
}