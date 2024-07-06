// Leetcode: Pass the Pillow
// https://leetcode.com/problems/pass-the-pillow

#include <iostream>

using namespace std;

int passThePillow(int n, int time)
{
  // Determine if the translation (movement) is towards the left or right
  bool leftTranslation = (time / (n - 1)) % 2 == 0;
  // Calculate the amount of translation (movement) within the range
  int translationAmount = time % (n - 1);

  // Return the resulting position based on the direction of translation
  return leftTranslation ? translationAmount + 1 : n - translationAmount;
}

int main()
{
  int n, time;
  cin >> n >> time;

  cout << passThePillow(n, time) << endl;

  return 0;
}