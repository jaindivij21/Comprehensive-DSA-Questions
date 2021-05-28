// Playing with cards in stack

#include<iostream>
#include<stack>
#include<vector>

#define MAX 100000
#define ll long long
using namespace std;

// prime sieve
vector<int> sieve;

// makes the sieve of primes
void makePrimeSieve() {
    int arr[MAX];
    arr[0] = arr[1] = 0;
    arr[2] = 1;
    for (ll i = 3; i < MAX; ++i) {
        if (i % 2 == 0)
            arr[i] = 0;
        else
            arr[i] = 1;
    }
    for (ll i = 3; i < MAX; i = i + 2) {
        if (arr[i] == 1) {
            for (ll j = i * i; j < MAX; j = j + i) {
                arr[j] = 0;
            }
        }
    }

    for (ll i = 0; i < MAX; i++) {
        if (arr[i] == 1)
            sieve.push_back(i);
    }
}

int main() {
    makePrimeSieve();

    // input the main information
    int num, iterations;
    cin >> num >> iterations;

    // make 2 vector(array) of stacks
    vector<stack<int>> A;
    vector<stack<int>> B;

    // INPORTANT (need to allocate declare the stacks at the vector indexes)
    A.emplace_back(stack<int>());
    B.emplace_back(stack<int>());
    
    // input A0
    for (int i = 1; i <= num; i++) {
        int data;
        cin >> data;
        A[0].push(data);
    }
    
    int i;
    for (i = 1; i <= iterations; i++) {
        // for every iteration 
        // make Ai and Bi
        A.emplace_back(stack<int>());
        B.emplace_back(stack<int>());
        while (!A[i - 1].empty()) {
            int temp = A[i - 1].top();
            A[i - 1].pop();
            // check divisibility by the prime and accordingly push into the Bi or Ai stack
            if (temp % sieve[i - 1] == 0) {
                B[i].push(temp);
            } else {
                A[i].push(temp);
            }
        }
    }


    // print the results
    for (int j = 1; j <= iterations; j++) {
        while (!B[j].empty()) {
            cout << B[j].top() << endl;
            B[j].pop();
        }
    }
    while (!A[iterations].empty()) {
        cout << A[iterations].top() << endl;
        A[iterations].pop();
    }

    return 0;
}