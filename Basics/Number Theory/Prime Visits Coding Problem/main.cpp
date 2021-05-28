#include<iostream>

using namespace std;
#define ll long long
#define MAX 1000000

void cumulativeArrayFormation(int arr2[], int arr[]) {
    int count = 0;
    for (ll i = 0; i < MAX; i++) {
        if (arr[i] == 1)
            count++;
        arr2[i] = count;
    }
}

// Make the prime sieve
void primeSieve(int arr[]) {
    arr[2] = 1;
    for (int i = 3; i < MAX; i += 2)
        arr[i] = 1;
    for (ll i = 3; i < MAX; i += 2) {
        if (arr[i] == 1) {
            for (ll j = i * i; j < MAX; j += i)
                arr[j] = 0;
        }
    }
}

int main() {
    // test cases (max = 1000)
    int n;
    cin >> n;

    // make the prime array
    int *primeNumbers = new int[MAX]{0};
    primeSieve(primeNumbers);
    // make the cumulative array
    int *cumulativePrimes = new int[MAX]{0};
    cumulativeArrayFormation(cumulativePrimes, primeNumbers);

    // for all the test cases
    while (n--) {
        ll a, b;
        cin>>a>>b;
        // print the total number of primes bw a and b (both inclusive, thats why a-1)
        cout<<cumulativePrimes[b] - cumulativePrimes[a-1]<<endl;
    }

    return 0;
}