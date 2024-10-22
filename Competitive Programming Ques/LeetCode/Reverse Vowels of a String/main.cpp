// Leetcode: Reverse Vowels of a String
// https://leetcode.com/problems/reverse-vowels-of-a-string

#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  string reverseVowels(string s)
  {
    // Define a set of vowel characters (considering lowercase vowels only)
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    // Initialize two pointers
    int left = 0, right = s.size() - 1;

    // Continue looping until the two pointers cross each other
    while (left < right)
    {
      // Move the left pointer forward until a vowel is found or the end of the string is reached
      while (left < right && vowels.find(s[left]) == vowels.end())
      {
        left++;
      }

      // Move the right pointer backward until a vowel is found or the beginning of the string is reached
      while (left < right && vowels.find(s[right]) == vowels.end())
      {
        right--;
      }

      // If both pointers have stopped at vowels, swap them and move both pointers inward
      if (left < right)
      {
        swap(s[left++], s[right--]);
      }
    }

    return s;
  }
};

int main()
{
  Solution sol;
  string s = "leetcode";
  string result = sol.reverseVowels(s);

  return 0;
}