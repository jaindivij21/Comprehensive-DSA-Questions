// Leetcode: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill
// Divide Players Into Teams of Equal Skill

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  long long dividePlayers(vector<int> &skill)
  {
    sort(skill.begin(), skill.end());

    vector<pair<int, int>> pairs;

    int s = 0, e = skill.size() - 1;
    int idealSum = skill[s] + skill[e];
    while (s < e)
    {
      if (idealSum != skill[s] + skill[e])
        return -1;

      pairs.emplace_back(skill[s++], skill[e--]);
    }

    long long chemistry = 0;
    for (auto pair : pairs)
    {
      chemistry += (pair.first * pair.second);
    }

    return chemistry;
  }
};

int main()
{
  Solution solution;
  vector<int> skill = {4, 5, 6, 7, 8, 9};
  cout << solution.dividePlayers(skill) << endl;

  return 0;
}