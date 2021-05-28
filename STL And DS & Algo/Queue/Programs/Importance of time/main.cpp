// Time is important

#include<iostream>
#include<queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cost = 0;

    // store the numbers in the queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        q.push(data);
    }

    int ideal[n];
    for (int i = 0; i < n; i++)
        cin >> ideal[i];

    for (int i = 0; i < n; i++) {
        // for all the n numbers/iterations

        // if the ideal and queue front match
        if (q.front() == ideal[i]) {
            cost++;
            q.pop();
        } else {
            int nextIdeal = ideal[i];
            while (q.front() != nextIdeal) {
                int temp = q.front();
                q.pop();
                q.push(temp);
                cost++;
            }
            cost++;
            q.pop();
        }
    }

    cout << cost << endl;
    return 0;
}