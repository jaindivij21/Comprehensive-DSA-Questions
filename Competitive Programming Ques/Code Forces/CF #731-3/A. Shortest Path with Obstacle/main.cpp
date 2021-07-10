// A. Shortest Path with Obstacle
 
#include<bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int y1, x1;
    cin >> y1 >> x1;
    int y2, x2;
    cin >> y2 >> x2;
    int fy, fx;
    cin >> fy >> fx;
 
    // cal the path between the 2 points
    int path = abs(y2 - y1) + abs(x2 - x1);
    // F point will be an obstruction only when all three lie in the same line, in such a case add 2
    if (fx == x1 && fx == x2) {
        // same row
        int minX = min(y1, y2);
        int maxX = max(y1, y2);
        if (fy < maxX && fy > minX)
            path += 2;
    } else if (fy == y1 && fy == y2) {
        // same column
        int minY = min(x1, x2);
        int maxY = max(x1, x2);
        if (fx < maxY && fx > minY)
            path += 2;
    }
 
    cout << path << endl;
}
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}