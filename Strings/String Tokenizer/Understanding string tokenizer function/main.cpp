// String Tokenizer Function

#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    // make/declare a string
    char str[100] = "Today is a rainy day";
    cout<<"The original string is: "<<str<<endl;

    cout<<"First Token: ";
    // strtok() returns a char pointer pointing towards the string's first token
    char *ptr = strtok(str," ");
    cout<<ptr<<endl;    // printing that char pointer gives us the first token

    cout<<"Second Token: ";
    // any subsequent calls of this strtok function will give us other tokens of that string until you change the string
    // so pass *NULL* instead of the string
    ptr = strtok(nullptr, " ");
    cout<<ptr<<endl;

    //////////////////////////
    cout<<"****************"<<endl;

    // Method to print all the tokens in one go
    char str2[100] = "My name is Divij";
    cout<<"The original string is: "<<str2<<endl;
    cout<<"The Tokens are:"<<endl;

    // make a loop to extract all the tokens
    ptr = strtok(str2, " ");    // space being the delimiter
    while(ptr != NULL)
    {
        cout<<ptr<<endl;
        ptr = strtok(NULL, " ");
    }

    return 0;
}