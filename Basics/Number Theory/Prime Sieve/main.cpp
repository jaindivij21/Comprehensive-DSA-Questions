// Program to implement Prime Sieve, i.e programt o tell if a number is prime or not
// Prime Sieve Time Complexity is O(NloglogN) which is almost O(N)

#include<iostream>

#define ll unsigned long long int
#define MAX 1000000
using namespace std;


void primeSieve(int arr[]) {
    arr[2] = 1; // since 2 is prime
    // mark all odd numbers and 2 as prime, since all even numbers are not prime except 2
    for (int i = 3; i < MAX; i += 2)
        arr[i] = 1;
    // at this point 1, 2, 3 and all odd numbers are marked prime

    // Sieve
    for (ll i = 3; i < MAX; i += 2) {
        // if the current number is marked as prime
        if (arr[i] == 1) {
            // mark all its multiples as non prime (Opitimization technique: mark all the multiples as not prime after i^2 instead of after i itself)
            // Ex. for 5, dont go on marking 10, 15, 20.. as not prime rather start directly from 25. Because 10, 15 etc will already be marked non prime by 2 and 3 respectively etc.
            for (ll j = i * i; j < MAX; j += i)
                arr[j] = 0;
        }
    }
}

int ifPrime(int num, int arr[]) {
    // if at num index the value is 1 means that the number is prime otherwise not
    if (arr[num] == 1)
        return 1;
    else
        return 0;
}

int main() {

    // NOTE: Make array global for it to be so big other wise you'll get segmentation fault
    // or you can use heap memory by using dynamic memory allocation for array instead os stack array

    // array tells if that number is prime or not
    int *primeNumbers = new int[MAX]{0};    // initially all are non prime
    primeSieve(primeNumbers);   // this function marks numbers that prime

    // Print all the prime numbers till 100 to check
    for (int i = 0; i < 101; i++) {
        if (primeNumbers[i] == 1)
            cout << i << " ";
    }

    cout << endl;

    cout << "Enter the number to find if its prime or not" << endl;
    int num;
    cin >> num;

    int ans = ifPrime(num, primeNumbers);

    // print output
    if (ans == 1)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    delete[]primeNumbers; // delete dynamically allocated array
    return 0;
}