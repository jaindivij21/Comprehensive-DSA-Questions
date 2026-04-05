// Leetcode: Robot Return to Origin
// https://leetcode.com/problems/robot-return-to-origin

#include <iostream>
#include <unordered_map>
using namespace std;

// Simulation
class Solution {
   public:
    bool judgeCircle(string moves) {
        unordered_map<char, pair<int, int>> coords{{'U', make_pair(0, 1)},
                                                   {'D', make_pair(0, -1)},
                                                   {'R', make_pair(1, 0)},
                                                   {'L', make_pair(-1, 0)}};

        int x = 0, y = 0;
        for (auto c : moves) {
            auto p = coords[c];
            x += p.first;
            y += p.second;
        }

        return (x == 0 && y == 0) ? true : false;
    }
};

int main() {
    Solution sol;
    string moves = "UUD";

    cout << sol.judgeCircle(moves) << endl;

    return 0;
}