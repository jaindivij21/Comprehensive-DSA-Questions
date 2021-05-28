// Print all the prime factors of a number using prime Sieve (O(NlglgN))

#include<iostream>
#include<vector>

using namespace std;
#define ll long long
#define MAX 1000000


// Make the prime sieve
vector<int> primeSieve(int arr[]) {
    arr[2] = 1;
    for (int i = 3; i < MAX; i += 2)
        arr[i] = 1;
    for (ll i = 3; i < MAX; i += 2) {
        if (arr[i] == 1) {
            for (ll j = i * i; j < MAX; j += i)
                arr[j] = 0;
        }
    }

    // make the vector
    vector<int> primes;
    primes.push_back(2);
    for (ll i = 3; i <= MAX; i += 2) {
        if (arr[i] == 1)
            primes.push_back(i);
    }
    return primes;
}

int main() {
    // test cases
    int n;
    cin >> n;

    // make the prime array
    int *primeNumbers = new int[MAX + 5]{0};
    vector<int> primes = primeSieve(primeNumbers);
    delete[] primeNumbers;

    // for all the test cases
    while (n--) {
        ll num;
        cin >> num;

        // find the prime factors of this number
        for (int i = 0; primes.at(i) * primes.at(i) < num; i++) {
            while (num % primes.at(i) == 0) {
                cout << primes.at(i) << " ";
                num /= primes.at(i);
            }
        }
        if(num!=1)
            cout<<num<<" ";
        else
            cout<<endl;
    }

    return 0;
}