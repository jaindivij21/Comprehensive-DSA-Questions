// Leetcode: Find Common Characters
// https://leetcode.com/problems/find-common-characters

#include <iostream>
#include <vector>

using namespace std;

vector<string> commonChars(vector<string> &words)
{
  unordered_map<char, int> final;

  for (const auto &character : words[0])
  {
    final[character]++;
  }

  for (int i = 1; i < words.size(); i++)
  {
    unordered_map<char, int> current;
    string currentWord = words[i];
    for (const auto &character : currentWord)
    {
      current[character]++;
    }

    // Compare the final and current arrays
    for (auto &pair : final)
    {
      if (current.find(pair.first) != current.end())
      {
        pair.second = min(pair.second, current[pair.first]);
      }
      else
      {
        pair.second = 0;
      }
    }
  }

  vector<string> ans;
  for (const auto &pair : final)
  {
    for (int i = 0; i < pair.second; i++)
    {
      string str;
      str.push_back(pair.first);
      ans.push_back(str);
    }
  }

  return ans;
}

int main()
{
  vector<string> words = {"bella", "label", "roller"};
  vector<string> ans = commonChars(words);

  for (const auto &i : ans)
  {
    cout << i << " ";
  }

  return 0;
}