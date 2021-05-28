// Von Neuman Loves Binary; tell deciaml from binary

#include<iostream>
#include<vector>  
#include<algorithm>
using namespace std;

int main()
{
    vector<int> v;
    char ch=0;
    while(ch != '\n' && ch!=EOF)
    {
        ch = cin.get();
        int num = ch - '0';
        v.push_back(num);
    } 
    // pop the last element since its '\n'
    v.pop_back();
    // reverse the array
    reverse(v.begin(), v.end());

    // find the decimal
    int sum = 0;
    int power = 1;
    for(int i = 0; i< v.size(); i++)
    {
        sum += v.at(i)*power;
        power <<= 1;
    }

    cout<<"The decimal for this binary is "<<sum<<endl;
    
    
    
    
    
    
    
    return 0;
}