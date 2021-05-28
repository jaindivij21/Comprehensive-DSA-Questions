// Program to find the first repeating character in a running stream of characters
/*
 *  For an input string, print an output string which contains the first non repeating character
 *  Ex.
 *  Input:     a a b c c b c d
 *  Output:    a * b b b * * d
 */

/*
 *  WORKING:
 *      1) Maintain a queue, insert the input string into the queue while also maintaining a freq map of the elements
 *      2) If the freq of the element if more than 1, pop the queue element until we get some element with
 *         one frequency, thus printing it.
 *      3) if however the queue gets empty means, there is no non repeating char thus print -1
 */

#include<iostream>
#include <queue>
#include<map>

using namespace std;

int main() {
    // input the char array
    char *str = new char[100];
    cout << "Enter the string of chars" << endl;
    cin >> str;

    char *output = new char[100];

    queue<char> q;
    map<char, int> freqMap;

    int i;
    for (i = 0; str[i] != '\0'; i++) {
        q.push(str[i]);
        freqMap[str[i]]++;

        while (!q.empty()) {
            if (freqMap[q.front()] > 1) {
                q.pop();
            } else {
                output[i] = q.front();
                break;
            }
        }
        if(q.empty())
            output[i] = '*';
    }

    output[i] = '\0';
    // print the output string
    for (int i = 0; output[i] != '\0'; i++) {
        cout << output[i] << " ";
    }
    cout << endl;

    return 0;
}