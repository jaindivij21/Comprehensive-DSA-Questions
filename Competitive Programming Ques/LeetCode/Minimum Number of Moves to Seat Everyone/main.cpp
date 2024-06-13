// Leetcode: Minimum Number of Moves to Seat Everyone
// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/

#include <iostream>
#include <vector>
using namespace std;

void sortArray(vector<int> &arr)
{
  vector<int> counts(101, 0);

  for (int i = 0; i < arr.size(); i++)
  {
    counts[arr[i]]++;
  }

  int j = 0;
  for (int i = 1; i < counts.size(); i++)
  {
    if (counts[i] == 0)
    {
      continue;
    }

    while (counts[i] != 0)
    {
      arr[j++] = i;
      counts[i]--;
    }
  }
}

int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
  sortArray(seats);
  sortArray(students);

  int answer = 0;
  for (int i = 0; i < seats.size(); i++)
  {
    answer += abs(students[i] - seats[i]);
  }

  return answer;
}

int main()
{
  vector<int> a = {3, 1, 5};
  vector<int> b = {2, 7, 4};

  cout << minMovesToSeat(a, b);

  return 0;
}