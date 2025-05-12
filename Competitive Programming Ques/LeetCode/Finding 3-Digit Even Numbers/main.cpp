// Leetcode: Finding 3-Digit Even Numbers
// https://leetcode.com/problems/finding-3-digit-even-numbers

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
   public:
    // Finds all unique 3-digit even numbers that can be formed using the given
    // digits
    vector<int> findEvenNumbers(const vector<int>& digits)
    {
        if (digits.size() < 3)
            return {};  // At least 3 digits are needed to form a 3-digit number

        // Count the frequency of each digit
        unordered_map<int, int> digitFrequency;
        for (int digit : digits)
        {
            digitFrequency[digit]++;
        }

        vector<int> validNumbers;

        // Check all 3-digit even numbers (100 to 998, incrementing by 2 to
        // ensure even)
        for (int number = 100; number <= 998; number += 2)
        {
            if (canFormNumber(number, digitFrequency))
            {
                validNumbers.push_back(number);
            }
        }

        return validNumbers;
    }

   private:
    // Determines whether a number can be formed using the available digits
    static bool canFormNumber(int number,
                              unordered_map<int, int> digitFrequency)
    {
        // Create a temporary map to avoid modifying the original frequency map
        while (number > 0)
        {
            int digit = number % 10;
            number /= 10;

            // If digit is not present or used up, the number cannot be formed
            if (digitFrequency[digit] == 0)
            {
                return false;
            }
            digitFrequency[digit]--;
        }

        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> digits = {10, 15, 20};

    for (const vector<int> ans = solution.findEvenNumbers(digits);
         const auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}
