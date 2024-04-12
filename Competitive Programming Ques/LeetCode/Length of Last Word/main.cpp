// Length of Last Word: Leetcode
// https://leetcode.com/problems/length-of-last-word/description/

#include <iostream>

using namespace std;

// Method to find the length of the last word in a string
int lengthOfLastWord(string s)
{
  int len = 0;
  int i = s.size() - 1;

  // Skip trailing spaces
  while (i >= 0 && s[i] == ' ')
  {
    i--;
  }

  // Count the length of the last word
  while (i >= 0 && s[i] != ' ')
  {
    len++;
    i--;
  }

  return len;
}

int main()
{
  string s;
  getline(cin, s);

  cout << lengthOfLastWord(s) << endl;

  return 0;
}