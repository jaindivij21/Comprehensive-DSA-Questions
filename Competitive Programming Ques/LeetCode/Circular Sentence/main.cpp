// Leetcode: Circular Sentence
// https://leetcode.com/problems/circular-sentence

#include <iostream>

using namespace std;

class Solution
{
public:
  bool isCircularSentence(string &sentence)
  {
    for (int i = 0; i < sentence.size(); i++)
    {
      if (i == sentence.size() - 1 && sentence[i] != sentence[0])
      {
        return false;
      }
      else if (sentence[i + 1] == ' ' && sentence[i] != sentence[i + 2])
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution sol;
  string sentence = "the sky is blue";

  cout << "Is the sentence circular: " << sol.isCircularSentence(sentence) << endl;

  return 0;
}