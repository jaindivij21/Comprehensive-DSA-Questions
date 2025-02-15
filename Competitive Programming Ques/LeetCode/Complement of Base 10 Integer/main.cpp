// Leetcode: Complement of Base 10 Integer
// https://leetcode.com/problems/complement-of-base-10-integer

#include <iostream>

using namespace std;

class Solution
{
public:
  int bitwiseComplement(int n)
  {
    vector<int> bits = convertDecToBin(n);
    for (int &bit : bits)
    {
      bit ^= 1;
    }

    return convertBinToDec(bits);
  }

private:
  static int convertBinToDec(const vector<int> &bits)
  {
    int num = 0;

    for (int bit : bits)
    {
      num = (num << 1) | bit;
    }

    return num;
  }

  static vector<int> convertDecToBin(int num)
  {
    if (num == 0)
      return {0};

    vector<int> bin;

    while (num != 0)
    {
      bin.push_back(num % 2);
      num /= 2;
    }

    reverse(bin.begin(), bin.end());
    return bin;
  }
};

int main()
{
  Solution s;
  int num = 5;

  cout << s.bitwiseComplement(num) << endl;

  return 0;
}