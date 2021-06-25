// https://www.codechef.com/START4C/problems/DEQUEUE
// https://www.youtube.com/watch?v=T5jzmqEEXmU

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin>>t;
    while (t--){
        ll n,m;
        cin>>n>>m;

        // array
        ll arr[m];
        // map to keep track of last index of each unique element in the array
        unordered_map<ll, ll> last_index;

        // input the array
        for(ll i = 0; i < m; i++){
            cin>>arr[i];
            last_index[arr[i]] = i;
        }

        // set to store all the last indexes (using set cuz it keeps things in order)
        set<ll> st;
        for(auto i: last_index){
            st.insert(i.second);
        }

        // initial ans would be when prefix is 0 and all the elements are popped from suffix
        ll ans = m-(*st.begin());

        // adding one by one to the prefix
        for(ll i = 0; i < m; i++){
            if(st.count(last_index[arr[i]]))
                st.erase(last_index[arr[i]]);
            if(!st.empty())
                ans = min(ans, i+1 + m - *st.begin());  // prefix + suffix
            else
                ans = min(ans, i+1);    // if suffix is empty (since set is empty) just take the prefix
        }
        cout << ans << "\n";
    }
    return 0;
}