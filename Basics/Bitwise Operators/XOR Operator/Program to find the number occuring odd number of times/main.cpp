// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int maxCities(vector<vector<char>> &a, int n, int m);


// Driver code to test above functions
int main()
{


    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<char>> a(n, vector<char>(m));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> a[i][j];
            }
        }

        cout << maxCities(a, n, m) << "\n";

    }


    return 0;
}// } Driver Code Ends


int maxCities(vector<vector<char>> &a, int n, int m)
{
    int exploredSet[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if (a[i][j] == '*')
            {
                for(int a=i-1; a<i+2; a++)
                {
                    for(int b=j-1; b<j+2; b++)
                    {
                        if(a<0 || a>=n || b<0 || b>=m)
                            continue;
                        else if (a==i && b ==j)
                            continue;
                        else
                        {
                            if(exploredSet[a][b] != 1)
                                exploredSet[a][b] = 1;
                            else
                                continue;
                        }
                    }
                }
            }
        }
    }

    int count = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(exploredSet[i][j] == 1)
            {
                count++;
            }
            else
            {
                exploredSet[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << exploredSet[i][j] << " ";
        }

        // Newline for new row
        cout << endl;
    }
    return count;
}