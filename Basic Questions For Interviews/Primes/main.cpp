// Find if a number is prime
// Generate a prime sieve (list of prime numbers)
// Print all the prime factors of a number

#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define MAX 1000000

bool ifPrime(int n)
{
    for (int i = 2; i <= n - 1; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<ll> makeSieve()
{
    vector<ll> sieve(MAX, 0); // 0 represents composite while 1 represents prime
    sieve[2] = 1;
    // make all the odds 1
    for (ll i = 3; i < sieve.size(); i += 2)
    {
        sieve[i] = 1;
    }
    // now make sure only the prime are 1
    for (ll i = 3; i <= MAX; i++)
    {
        // traverse over all the numbers and if the number is 1 (prime) and sure it's multiples are marked non prime
        if (sieve[i] == 1)
        {
            for (ll j = i * i; j <= MAX; j = j + i)
            {
                sieve[j] = 0;
            }
        }
    }

    vector<ll> primes;
    primes.push_back(2);
    for (ll i = 3; i <= MAX; i += 2)
    {
        if (sieve[i] == 1)
        {
            primes.push_back(i);
        }
    }
    return primes;
}

// 10 - 2 (5) 3 5 (0)
// 26 - 2(13)
vector<ll> calPrimeFactor(ll num, vector<ll> &primes)
{
    vector<ll> factors;
    for (auto i : primes)
    {
        if (num == 0)
        {
            break;
        }
        else
        {
            while (num % i == 0)
            {
                factors.push_back(i);
                num /= i;
            }
        }
    }
    return factors;
}

int main()
{
    int n = 52;
    vector<ll> primes = makeSieve();
    vector<ll> fac = calPrimeFactor(n, primes);
    for (auto i : fac)
        cout << i << " ";
    return 0;
}