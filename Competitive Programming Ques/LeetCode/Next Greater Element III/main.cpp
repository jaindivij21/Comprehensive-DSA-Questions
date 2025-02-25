// Leetcode: Next Greater Element III
// https://leetcode.com/problems/next-greater-element-iii

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    int nextGreaterElement(int n)
    {
        vector<int> digits = convertNumToVector(n);

        int i = digits.size() - 1;
        while (i > 0 && digits[i - 1] >= digits[i])
        {
            i--;
        }

        if (i == 0) return -1;

        int j = digits.size() - 1;
        while (digits[j] <= digits[i - 1])
        {
            j--;
        }

        swap(digits[i - 1], digits[j]);
        sort(digits.begin() + i, digits.end());

        return convertVectorToNum(digits) > INT_MAX
                   ? -1
                   : convertVectorToNum(digits);
    }

   private:
    long long int convertVectorToNum(vector<int> &digits)
    {
        long long int num = 0;
        long long int p = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            num += digits[i] * p;
            p *= 10;
        }

        return num;
    }

    vector<int> convertNumToVector(int n)
    {
        vector<int> digits;

        while (n != 0)
        {
            digits.push_back(n % 10);
            n /= 10;
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};

int main()
{
    Solution s;
    cout << s.nextGreaterElement(230241) << endl;

    return 0;
}