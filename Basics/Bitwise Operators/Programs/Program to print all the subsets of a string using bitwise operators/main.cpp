// Program to find subsets of a given string
/*
 *  INPUT
 *  abc
 *  OUTPUT
 *  " ", a, b, c, ab, bc, ac, abc
 */

// LOGIC
// basically consider each postion as binary, either its there (1) or not (0)
// i.e 111 = abc || 000 = " "

#include <cstring>
#include <iostream>
#include <math.h>

using namespace std;

// func
void printAllSubsets(char str[])
{
    int tempLen = strlen(str); // cal the string's len
    // int len = pow(2, tempLen); // cal the 2^tempLen == the number of subsets of that string

    // for each subset (ex for abc = 8 subsets)
    for (int i = 0; i < (1 << tempLen); i++)
    {
        int ptr = tempLen - 1; // pointer points at the last char in string
        int temp = i;          // value of i stored in temp so that loop is not affected
        // for that subset/value of temp
        while (temp > 0)
        {
            int lastBit = temp & 1;
            if (lastBit)
            {
                // if the bit is 1 at that position, print the char at the position
                cout << str[ptr];
            }
            ptr--;
            temp >>= 1;
        }
        cout << endl;
    }
}

// main program
int main()
{
    char str[100];
    cout << "Enter the string" << endl;
    cin >> str;
    printAllSubsets(str);
    return 0;
}