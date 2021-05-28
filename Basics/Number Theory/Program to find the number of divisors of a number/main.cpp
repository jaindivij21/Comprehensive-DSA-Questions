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

    // make the vector that contains only the prime numbers
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
        // input the number whose number of divisors are to be found
        ll num;
        cin >> num;

        int count = 0;  // this keeps the value of number of times a factor occurs. eg. in 12 = 2*2*3 == 2 occurs (two) times
        int ans = 1;    // this stores our ans (check logic.txt for logic)

        // find the number of divisors of this number
        for (int i = 0; primes.at(i) * primes.at(i) < num; i++) {
            // for every prime
            // check if that prime divides the number, if yes increment count and update the number 
            while (num % primes.at(i) == 0) {
                count++;
                num /= primes.at(i);
            }
            // out of the while loop, update ans acc to the logic and reset count 
            ans *= (count + 1);
            count = 0;
        }
        // corner case
        if (num != 1)
            ans *= 2;

        cout << "The number of divisors are: " << ans << endl;
    }

    return 0;
}