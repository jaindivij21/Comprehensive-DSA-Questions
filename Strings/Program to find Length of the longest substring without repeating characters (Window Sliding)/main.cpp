// Length of the longest substring without repeating characters
// Technique used: *WINDOW SLIDING*  (O(n^2))

#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void getAns(string str, int len)
{
    int maxi = 0;                                                                        //0

    for(int i = 0; i < len; i++)
    {
        // geeksforgeeks
        vector<bool> visited(256);
        for(int j = i; j < len; j++)
        {
            if(visited[str[j]] == true)
                break;
            else
            {
                maxi = max(j-i+1, maxi);
                visited[str[j]] = true;
            }
        }
        visited[str[i]] = false;
    }
    cout<<"The ans: "<<maxi<<endl;
}

int main()
{
    cout<<"Enter the string:";
    string str;
    getline(cin, str);

    int len = str.length();

    getAns(str, len);

    return 0;
}
