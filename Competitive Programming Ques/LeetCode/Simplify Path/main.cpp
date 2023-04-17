// Leetcode: Simplify Path
// https://leetcode.com/problems/simplify-path/

#include <iostream>
#include <stack>

using namespace std;

// Function to simplify the string
string simplifyPath(string path)
{
  string ans;        // Answer String
  stack<string> dir; // Stack to store the name of each directory

  // Loop over the entire path string
  int i = 0;
  while (i < path.size())
  {
    switch (path[i])
    {
    case '/':
      // If it's a slash, ignore and move forward
      i++;
      break;
    default:
      // Else store in a temp variable
      string directory = "";
      while (path[i] != '/' && i < path.size())
      {
        directory += path[i++];
      }

      if (directory == ".")
        // If the temp variable is '.', do nothing
        break;
      else if (directory == "..")
      {
        // If its '..', pop the last directory
        if (!dir.empty())
          dir.pop();
      }
      else
        // Else just push into the stack and add it to the directories
        dir.push(directory);
    }
  }

  // Convert the stack into a final address string
  if (dir.empty())
  {
    ans += "/";
  }
  else
  {
    while (!dir.empty())
    {
      ans = "/" + dir.top() + ans;
      dir.pop();
    }
  }

  // return the ans
  return ans;
}

int main()
{
  string str = "/../";
  string ans = simplifyPath(str);

  cout << ans << endl;

  return 0;
}