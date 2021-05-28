// https://codeforces.com/contest/1400/problem/A

// program question 1

#include<iostream>
#include<vector>
using namespace std;

//void binaryOpposite(int n, int l)
//{
//    vector<int> v;
//    while (n > 0) {
//        v.push_back(n % 2);
//        n = n / 2;
//    }
////    int size = v.size();
////    if(size<n)
////    {
////        for(int i =0; i<(n-size); i++)
////        {
////            v.insert(v.begin(),0);
////        }
////    }
//    for(auto & itr: v)
//    {
//        cout<<v[itr];
//    }
//    cout<<endl;
//}

void binaryOpposite(int final, int n) {
    int pos = 1;
    int ans = 0;
    while (final != 0)
    {
        int r = final % 2;
        ans += pos* r;
        pos = pos*10;
        final = final/2;
    }
    string s = to_string(ans);
    int len = s.length();
    if (len<n)
    {
        for(int i =0; i<n-len; i++)
        {
            string str2 = "0";
            s.insert(0,str2);
        }
    }
    cout<<s<<endl;
}

int binaryConvert(int n)
{
    int num = n;
    int dec = 0;
    int base = 1;
    int temp = num;
    while(temp)
    {
        int last_digit =  temp % 10;
        temp = temp/10;
        dec += last_digit*base;
        base = base*2;
    }
    return dec;
}

void similar(string str, int n)
{
    int temp = binaryConvert(stoi(str.substr(0,n)));
    int final = temp^0; // final=14
    for(int j = 1; j<n ;j++)
    {
        int temp2 = binaryConvert(stoi(str.substr(j, n)));
        final = final^temp2;
    }
    binaryOpposite(final,n);
}

int main()
{
    unsigned short int testCases, i;
    cin>>testCases;

    for(i = 0; i<testCases; i++)
    {
        int limit;
        cin>>limit;
        string str;
        cin>>str;
        similar(str,limit);
    }

    return 0;
}