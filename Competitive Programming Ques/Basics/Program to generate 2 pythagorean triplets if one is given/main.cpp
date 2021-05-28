// Generate Pythagorean Triplets in incresing order if given one number

#include <bits/stdc++.h>
#include<vector>

using namespace std;
typedef unsigned long long ll;

// Complete the pythagoreanTriple function below.
vector<ll> pythagoreanTriple(ll a) {
    vector<ll> temp;
    ll b,c;
    // if a is even
    if (a%2 == 0)
    {
        b=(a*a)/4 -1;
        c = b+2;
    }
    else
    {
        b = ((a*a) -1)/2;
        c = b+1;
    }
    temp.push_back(a);
    temp.push_back(b);
    temp.push_back(c);
    return temp;
}

int main()
{

    ll a;
    cout<<"Enter the first pythagorean triplet"<<endl;
    cin >> a;
    vector<ll> triple = pythagoreanTriple(a);

    for (int i = 0; i < triple.size(); i++) {
        cout << triple[i];

        if (i != triple.size() - 1) {
            cout << " ";
        }
    }

    cout << "\n";
    return 0;
}
