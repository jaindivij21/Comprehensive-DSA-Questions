// Leetcode : Goal Parser Interpretation
// https://leetcode.com/problems/goal-parser-interpretation/

#include <bits/stdc++.h>

using namespace std;

string interpret(string &command)
{
    string str;
    for (int i = 0; i < command.size(); i++)
    {
        if (command[i] == 'G')
            str += 'G';
        else if (command[i] == '(' && command[i + 1] == ')')
        {
            str += 'o';
            i++;
        }
        else
        {
            str += "al";
            i += 3;
        }
    }
    return str;
}

int main()
{

    return 0;
}