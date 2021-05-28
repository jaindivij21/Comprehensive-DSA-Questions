// program to swap two strings

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    char str1[1000];
    char str2[1000];

    cout<<"Input both the strings "<<endl;
    cin.getline(str1, 1000);
    cin.getline(str2, 1000);

    // there are two methods

    // 1
    char temp[1000];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);

    cout<<"The strings after 1st swap are: "<<str1<<" "<<str2<<endl;

    // 2
    char temp2[1000];
    int i;
    for(i = 0; str1[i] != '\0'; i++)
            temp[i] = str1[i];
    temp[i] = '\0';
    for(i = 0; str2[i] != '\0'; i++)
        str1[i] = str2[i];
    str1[i] = '\0';
    for(i = 0; temp[i] != '\0'; i++)
        str2[i] = temp[i];
    str2[i] = '\0';

    cout<<"The strings after 2st swap are: "<<str1<<" "<<str2<<endl;

    // 3 
    swap(str1, str2);
    cout<<"The strings after 3st swap are: "<<str1<<" "<<str2<<endl;

    return 0;
}