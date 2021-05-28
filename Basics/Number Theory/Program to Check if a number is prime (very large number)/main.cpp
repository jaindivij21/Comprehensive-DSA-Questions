// Check for a prime or not for a very large number (10^10 can be the order of number)

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

    // make the prime array
    int *primeNumbers = new int[MAX]{0};
    vector<int> primes = primeSieve(primeNumbers);  // contains only the prime numbers
    delete[] primeNumbers;


    ll num;
    cin >> num;

    // check if its a prime
    // basically checking if any prime divides the num till i is less than sqrt(num). If yes then the number is not prime otherwise it is!
    for (ll i = 0; (ll)primes.at(i) * (ll) primes.at(i) < num; i++) {    // used (Long long) to avoid overflow
        if (num % primes.at(i) == 0){
            cout << "Its not prime" << endl;
            exit(0);
        }
    }
    cout << "Its prime" << endl;


    return 0;
}