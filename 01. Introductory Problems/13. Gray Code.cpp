#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;
 
vector<string> gc(ll n){
    if(n==1) return {"0", "1"};
    vector<string>graycode;
    vector<string> prev = gc(n-1);
    for(auto s:prev){
        graycode.push_back("0"+s);
    }
    reverse(prev.begin(), prev.end());
    for(auto s:prev){
        graycode.push_back("1"+s);
    }
    return graycode;
}
 
void solve(){
    ll n;
    cin>>n;
    vector<string> grcode = gc(n);
    for(auto av:grcode){
        cout<<av<<nl;
    }
}
 
int main(){
    FASTER
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    //}
}
 
 
 
 
/*
One way to create a Gray code of length n is to use recursion. Suppose that we already have a list of strings which is a Gray code of length n-1. Using that list, we can create a Gray code of length n as follows:
Go through the list and, for each string s, add a string 0s to the code.
Reverse the list.
Go through the list and, for each string s, add a string 1s to the code.
For example, given a Gray code [00, 01, 11, 10] of length 2, we can create a Gray code [000, 001, 011, 010, 110, 111, 101, 100] of length 3.
*/

// Another:

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;
 
void solve(){
    ll n;
    cin>>n;
    vector<string>gray;
    gray.push_back("");     // starts with null, base case for 0 bits
    for(int i=0; i<n; i++){
        ll sz = gray.size();
        for(int j=sz-1; j>=0; j--){   // mirror the n-1 gray code, its doing the reverse copy
            gray.push_back(gray[j]);
        }
        for(int j=0; j<sz; j++){      // for first halves, original order + add '0' in front
            gray[j] = "0"+gray[j];
        }
        for(int j=sz; j<2*sz; j++){   // for last halves, reverse order + add '1' in front
            gray[j] = "1"+gray[j];
        }
    }
 
    for(int i=0; i<gray.size(); i++){
        cout<<gray[i]<<nl;
    }
}
 
int main(){
    FASTER
    solve();
}
