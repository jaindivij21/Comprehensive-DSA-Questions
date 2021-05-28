// THE LEAD GAME
// https://www.codechef.com/problems/TLG

#include<bits/stdc++.h>

using namespace std;

int main() {
    int cumSum1 = 0, cumSum2 = 0;
    pair<int, int> lead;
    lead.second = INT_MIN;

    int rounds;
    cin >> rounds;

    for (int i = 0; i < rounds; i++) {
        int x, y;
        cin >> x >> y;

        cumSum1 += x;
        cumSum2 += y;

        if (cumSum1 >= cumSum2 && (cumSum1 - cumSum2) > lead.second) {
            lead.first = 1;
            lead.second = cumSum1 - cumSum2;
        }
        if (cumSum2 >= cumSum1 && (cumSum2 - cumSum1) > lead.second) {
            lead.first = 2;
            lead.second = cumSum2 - cumSum1;
        }
    }

    cout << lead.first << " " << lead.second << endl;

    return 0;
}