// Leetcode: Check If a Word Occurs As a Prefix of Any Word in a Sentence
// https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence

#include <iostream>

using namespace std;

class Solution
{
public:
  // Determines if searchWord is a prefix of any word in the sentence.
  int isPrefixOfWord(string &sentence, string &searchWord)
  {
    int wordNum = 0; // Tracks the current word number.

    for (int i = 0; i < sentence.size(); i++)
    {
      // Start of a new word.
      if (i == 0 || sentence[i - 1] == ' ')
      {
        wordNum++;

        // Check if searchWord matches the prefix of the current word.
        if (sentence.substr(i, searchWord.size()) == searchWord)
        {
          return wordNum;
        }
      }
    }

    // No match found.
    return -1;
  }
};

int main()
{
  Solution sol;
  string sentence = "i love eating burger";
  string searchWord = "burg";
  cout << sol.isPrefixOfWord(sentence, searchWord) << endl;

  return 0;
}