// https://www.codechef.com/LTIME96B/problems/CHARGES

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n, k;
		string s;
		cin >> n >> k;
		cin >> s;
		int total = 0;
		for(int i = 0; i < n - 1; i++){
			if(s[i] == s[i + 1])
				total += 2;
			else
				total += 1;
		}
		for(int i = 0; i < k; i++){
			int input;
			cin >> input;
			input--;
			if(s[input] == '0')
				s[input] = '1';
			else
				s[input] = '0';
			if(input > 0){
				if(s[input] == s[input - 1])
					total += 1;
				else
					total -= 1;
			}
			if(input < n - 1){
				if(s[input] == s[input + 1])
					total += 1;
				else
					total -= 1;
			}
			cout << total << endl;
		}
	}
	return 0;
}