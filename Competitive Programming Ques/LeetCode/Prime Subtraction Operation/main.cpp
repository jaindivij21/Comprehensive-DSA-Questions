// Leetcode: Prime Subtraction Operation
// https://leetcode.com/problems/prime-subtraction-operation

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  bool primeSubOperation(vector<int> &nums)
  {
    vector<int> primes = generatePrimes(); // Generate primes less than 1000
    int previousValue = INT_MIN;           // Initialize previous value to minimum integer

    for (int num : nums)
    {
      int currentValue = num;
      int primeIndex = findLargestPrimeLessThan(primes, currentValue);

      // Main loop: Try to make currentValue strictly greater than previousValue by subtracting primes
      while (currentValue > previousValue && primeIndex < primes.size())
      {
        currentValue = num - primes[primeIndex];
        if (currentValue > previousValue)
          break;
        else
        {
          currentValue = num;
          primeIndex--;
        }
      }

      if (currentValue <= previousValue)
        return false;

      previousValue = currentValue; // Update previousValue to the new modified currentValue
    }

    return true;
  }

private:
  // Uses binary search to find the largest prime less than x
  int findLargestPrimeLessThan(vector<int> &primes, int x)
  {
    int left = 0, right = primes.size() - 1;
    int bestIndex = -1;

    while (left <= right)
    {
      int mid = left + (right - left) / 2;

      if (primes[mid] < x)
      {
        bestIndex = mid; // Keep track of the largest prime < x
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }

    return bestIndex;
  }

  // Generates all primes less than 1000 using the Sieve of Eratosthenes
  vector<int> generatePrimes()
  {
    vector<int> primes;
    vector<int> primeSieve(1001, 0);

    primeSieve[2] = 1;
    for (int i = 3; i < 1001; i += 2)
      primeSieve[i] = 1;

    for (int i = 3; i < 1001; i += 2)
    {
      if (primeSieve[i] == 1)
      {
        for (int j = 2; i * j < 1001; j++)
        {
          primeSieve[i * j] = 0;
        }
      }
    }

    for (int i = 0; i < primeSieve.size(); i++)
    {
      if (primeSieve[i] == 1)
      {
        primes.push_back(i);
      }
    }

    return primes;
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {4, 9, 6, 10};

  cout << sol.primeSubOperation(nums) << endl;

  return 0;
}