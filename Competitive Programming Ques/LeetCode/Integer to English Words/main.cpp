// Leetcode: Integer to English Words
// https://leetcode.com/problems/integer-to-english-words

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  // Map to store number to words mapping
  unordered_map<int, string> numToWords = {
      {0, "Zero"},
      {1, "One"},
      {2, "Two"},
      {3, "Three"},
      {4, "Four"},
      {5, "Five"},
      {6, "Six"},
      {7, "Seven"},
      {8, "Eight"},
      {9, "Nine"},
      {10, "Ten"},
      {11, "Eleven"},
      {12, "Twelve"},
      {13, "Thirteen"},
      {14, "Fourteen"},
      {15, "Fifteen"},
      {16, "Sixteen"},
      {17, "Seventeen"},
      {18, "Eighteen"},
      {19, "Nineteen"},
      {20, "Twenty"},
      {30, "Thirty"},
      {40, "Forty"},
      {50, "Fifty"},
      {60, "Sixty"},
      {70, "Seventy"},
      {80, "Eighty"},
      {90, "Ninety"},
      {100, "Hundred"},
      {1000, "Thousand"},
      {1000000, "Million"},
      {1000000000, "Billion"}};

  // Main function to convert a number to words
  string numberToWords(int num)
  {
    if (num <= 20)
    {
      return numToWords[num];
    }
    if (num < 100)
    {
      return numToWords[(num / 10) * 10] + (num % 10 ? " " + numToWords[num % 10] : "");
    }
    return convertToWordsHelper(num);
  }

private:
  // Helper function to handle conversions for larger numbers
  string convertToWordsHelper(int num)
  {
    if (num < 10)
    {
      return numToWords[num];
    }
    if (num < 20)
    {
      return numToWords[num];
    }
    if (num < 100)
    {
      return numToWords[(num / 10) * 10] + (num % 10 ? " " + numToWords[num % 10] : "");
    }
    else if (num < 1000)
    {
      return numToWords[num / 100] + " " + numToWords[100] +
             (num % 100 ? " " + convertToWordsHelper(num % 100) : "");
    }
    else if (num < 1000000)
    {
      return convertToWordsHelper(num / 1000) + " " + numToWords[1000] +
             (num % 1000 ? " " + convertToWordsHelper(num % 1000) : "");
    }
    else if (num < 1000000000)
    {
      return convertToWordsHelper(num / 1000000) + " " + numToWords[1000000] +
             (num % 1000000 ? " " + convertToWordsHelper(num % 1000000) : "");
    }
    else
    {
      return convertToWordsHelper(num / 1000000000) + " " + numToWords[1000000000] +
             (num % 1000000000 ? " " + convertToWordsHelper(num % 1000000000) : "");
    }
  }
};

int main()
{
  int num = 100;

  Solution s;
  cout << s.numberToWords(num) << endl;

  return 0;
}