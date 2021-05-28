#include<iostream>  
using namespace std;  
int main()  
{  
string str1 = "C++ is a language";  
string str2 = "programming ";  
cout<<"String contains :" <<str1<<'\n';  
cout<<"After insertion, String is :"<< str1.insert(9,str2);  
return 0;  
}   