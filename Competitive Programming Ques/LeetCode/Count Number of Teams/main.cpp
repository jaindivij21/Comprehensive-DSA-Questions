// Leetcode: Count Number of Teams
// https://leetcode.com/problems/count-number-of-teams

// Hint: https://leetcode.com/problems/count-number-of-teams/description/comments/2545232

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int numTeams(vector<int> &rating)
  {
    int totalTeams = 0;
    int n = rating.size();

    // Iterate through each possible middle soldier
    for (int middle = 1; middle <= n - 2; middle++)
    {
      int middleRating = rating[middle];

      // Counters for soldiers on the left and right of the middle soldier
      int leftGreater = 0, leftSmaller = 0;
      int rightGreater = 0, rightSmaller = 0;

      // Count soldiers on the left of the middle soldier
      for (int left = middle - 1; left >= 0; left--)
      {
        if (rating[left] > middleRating)
          leftGreater++;
        else if (rating[left] < middleRating)
          leftSmaller++;
      }

      // Count soldiers on the right of the middle soldier
      for (int right = middle + 1; right < n; right++)
      {
        if (rating[right] > middleRating)
          rightGreater++;
        else if (rating[right] < middleRating)
          rightSmaller++;
      }

      // Calculate the number of valid teams using the current middle soldier
      // Case 1: rating[left] < rating[middle] < rating[right]
      if (leftSmaller > 0 && rightGreater > 0)
        totalTeams += leftSmaller * rightGreater;

      // Case 2: rating[left] > rating[middle] > rating[right]
      if (leftGreater > 0 && rightSmaller > 0)
        totalTeams += leftGreater * rightSmaller;
    }

    return totalTeams;
  }
};

int main()
{
  vector<int> rating = {1, 2, 3, 4};

  Solution s;
  cout << s.numTeams(rating) << endl;
  return 0;
}