// Program to find the first non repeating character in a string

#include<iostream>
#include<cstring>
using namespace std;
#define NO_OF_CHARS 256

int main()
{
    string str;
    cout<<"Enter the string"<<endl;
    getline(cin,str);

    int hashMap[NO_OF_CHARS] = {0};

    for(int i = 0; str[i] != '\0'; i++)
    {
        hashMap[str[i]]++;
    }
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(hashMap[str[i]]==1) {
            cout << "ANS:" << str[i] << endl;
            break;
        }
    }
    return 0;
}