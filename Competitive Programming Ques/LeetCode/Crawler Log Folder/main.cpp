// Leetcode: Crawler Log Folder
// https://leetcode.com/problems/crawler-log-folder

#include <iostream>
#include <vector>

using namespace std;

int minOperations(std::vector<std::string> &logs)
{
  int res = 0;

  for (const string &log : logs)
  {
    if (log == "../")
    {
      if (res > 0)
      {
        res--;
      }
    }
    else if (log != "./")
    {
      res++;
    }
  }

  return res;
}

int main()
{
  vector<string> logs = {"d1/", "../", "../", "../"};
  cout << minOperations(logs) << endl;
  return 0;
}
