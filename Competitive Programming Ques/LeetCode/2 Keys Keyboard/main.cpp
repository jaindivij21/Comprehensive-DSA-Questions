// Leetcode: 2 Keys Keyboard
// https://leetcode.com/problems/2-keys-keyboard/description

#include <iostream>

using namespace std;

class Solution
{
public:
  int minSteps(int n)
  {
    // If n is 1, no steps are needed because we already have one 'A' on the screen.
    if (n == 1)
      return 0;

    // Start the recursive backtracking from the initial state:
    // 1 'A' on the screen, and the clipboard starts empty (1 'A' copied initially).
    return 1 + minStepsHelper(n, 1, 1);
  }

private:
  int minStepsHelper(int &target, int currentCount, int clipboardCount)
  {
    // Base Case 1: If we have exactly 'n' 'A's on the screen, no more steps are needed.
    if (currentCount == target)
      return 0;

    // Base Case 2: If the count exceeds 'n', this path is not valid, return a large value.
    if (currentCount > target)
      return 1000;

    // Recursive Case 1: Paste from clipboard. This will add `clipboardCount` 'A's to the screen.
    int pasteSteps = 1 + minStepsHelper(target, currentCount + clipboardCount, clipboardCount);

    // Recursive Case 2: Copy all and paste. This will double the `currentCount` on the screen.
    // We need 2 steps: one for copying the current content, and one for pasting.
    int copyPasteSteps = 2 + minStepsHelper(target, currentCount * 2, currentCount);

    // Return the minimum of the two possible actions.
    return min(pasteSteps, copyPasteSteps);
  }
};

int main()
{
  Solution s;
  cout << s.minSteps(6) << endl;

  return 0;
}
