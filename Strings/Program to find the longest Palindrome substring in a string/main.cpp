// Program to find the longest palindrome substr.
// Method: Brute Force O(n3)

#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

// forgeeksskeegfor  geeksskeeg
void findPalindrome(string str, int length)
{
    int max = 0, flag = 0;
    string temp;
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            for(int k = 0; k <= (j-i)/2; k++)
            {
                if(str[i+k] != str[j-k])
                {
                    flag = -1;
                    break;
                }
                else
                    flag = 1;
            }
            if(flag == 1)
            {
                // means its a palindrome, now check its length and if store it in temp string
                if (max < (j-i+1))
                {
                    max = j-i+1;
                    temp = str.substr(i,(j-i+1));
                }
            }
        }
    }
    cout<<"The longest palindrome in this string is: "<<temp<<endl;
}

int main()
{
    // input the strings
    string str;
    cout<<"Enter the first string:";
    getline(cin, str);

    int len = str.length();
    findPalindrome(str, len);
}