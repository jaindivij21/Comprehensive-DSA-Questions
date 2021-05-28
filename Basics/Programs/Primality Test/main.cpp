// Primality Test
// Check if a number is prime
// Better Soln O(underroot of n)

// A optimized school method based C++ program to check 
// if a number is prime 
#include <bits/stdc++.h> 
using namespace std; 
  
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 

    // All cases are covered for 6k+0, 6k+2, 6k+4 and 6k+3
    if (n%2 == 0 || n%3 == 0) return false; 

    // now for the number check if its divisible by 6k(+_)1 
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 

// Driver Program to test above function 
int main() 
{ 
    isPrime(11)?  cout << " true\n": cout << " false\n"; 
    isPrime(15)?  cout << " true\n": cout << " false\n"; 
    return 0; 
} 
