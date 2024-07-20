// Leetcode: Count Substrings That Differ by One Character
// https://leetcode.com/problems/count-substrings-that-differ-by-one-character

#include <iostream>
#include <vector>

using namespace std;

class BruteForceSolution
{
public:
  // Function to count the number of substrings in `s` that differ from some substring in `t` by exactly one character
  int countSubstrings(const string &s, const string &t)
  {
    // Generate all substrings of s and t
    vector<string> sSubstrings = getAllSubstrings(s);
    vector<string> tSubstrings = getAllSubstrings(t);

    int similarCount = 0;
    // Compare each substring of s with each substring of t
    for (const auto &sSubstr : sSubstrings)
    {
      for (const auto &tSubstr : tSubstrings)
      {
        // Check if the current substrings differ by exactly one character
        if (areSimilarByOneChar(sSubstr, tSubstr))
        {
          similarCount++;
        }
      }
    }

    return similarCount;
  }

private:
  // Function to check if two strings are similar by exactly one character
  bool areSimilarByOneChar(const string &str1, const string &str2)
  {
    // If the lengths of the strings are different, they can't be similar by one character
    if (str1.size() != str2.size())
    {
      return false;
    }

    int diffCount = 0;
    // Iterate through the strings and count the number of differing characters
    for (int i = 0; i < str1.size(); i++)
    {
      if (str1[i] != str2[i])
      {
        diffCount++;
      }
    }

    // Return true if there is exactly one differing character, otherwise false
    return diffCount == 1;
  }

  // Function to generate all substrings of a given string
  vector<string> getAllSubstrings(const string &str)
  {
    vector<string> substrings;

    // Iterate over all possible starting indices of substrings
    for (int start = 0; start < str.size(); start++)
    {
      // Iterate over all possible ending indices of substrings starting from the current start index
      for (int end = start; end < str.size(); end++)
      {
        // Extract and store the substring from start to end indices
        substrings.push_back(str.substr(start, end - start + 1));
      }
    }

    return substrings;
  }
};

int main()
{
  string s, t;
  cin >> s >> t;

  BruteForceSolution bfs;
  cout << bfs.countSubstrings(s, t) << endl;

  return 0;
}
