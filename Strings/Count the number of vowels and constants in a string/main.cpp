// Program to count number of digits, consonants, vowels and white spaces in string

#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;


int main()
{
    string str;
    cout<<"Input the string: ";
    getline(cin,str);

    int spaces = 0, consonants = 0, vowels = 0, digits = 0, spcls = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(isdigit(str[i]))
            digits++;
        else if(isblank(str[i]))
            spaces++;
        else if(str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'U' || str[i] == 'u')
            vowels++;
        // else if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z'))
        else if (isalpha(str[i]))
            consonants++;
        else
            spcls++;
    }
    cout<<"Digit: "<<digits<<endl;
    cout<<"Spaces: "<<spaces<<endl;
    cout<<"Consonants: "<<consonants<<endl;
    cout<<"Spcls: "<<spcls<<endl;
    cout<<"Vowels: "<<vowels<<endl;
    return 0;
}