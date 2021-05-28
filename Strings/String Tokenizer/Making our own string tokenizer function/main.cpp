// String Tokenizer Function

#include<iostream>
#include<cstring>
using namespace std;

char * mystrtok(char *s, char del)
{
    // basically this function accepts a string as a ptr to a char array and also a char del i.e the delemiter

    // maintain a static char input
    static char *input = NULL;

    // if input string isn't NULL, this char pointer will point to the first token
    if(s != NULL)
    {
        // making the first call
        input = s;
    }
    // base case, *AFTER THE FINAL TOKEN HAS BEEN RETURNED*
    if(input == NULL)
        return NULL;

    // need to make a *DYNAMIC ARRAY* to store tokens in
    char *output = new char[strlen(input)+1];
    int i = 0;
    for(; input[i] != '\0'; i++)
    {
        if(input[i]!=del)
            output[i] = input[i];
        else
        {
            output[i] = '\0';
            input += (i+1);
            return output;
        }
    }
    // corner case; there may not be a space at the end of the string
    output[i] = '\0';
    input = NULL;
    return output;
}

int main()
{
    // make/declare a string
    char str[100] = "Today is a rainy day";
    cout<<"The original string is: "<<str<<endl;

    // calling strtok function that we created
    char *ptr = mystrtok(str, ' ');
    while(ptr != NULL)
    {
        cout<<ptr<<endl;
        ptr = mystrtok(NULL, ' ');
    }

    return 0;
}