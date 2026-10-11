// Same idea for Josephus Problem I, but here k is given, remove the (k+1)th child. Means 1 to K are safe then remove the next untill the n's size is 1.

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
    ll n,k;
    cin>>n>>k;
    ordered_set<ll>s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }
    ll idx = 0;
    while(!s.empty()){
        idx = (idx+k) % s.size();   // remove the (k+1)th
        auto it = s.find_by_order(idx);  // give me the ele in the position idx in sorted order
        cout<<*it<<" ";
        s.erase(it);
    }
    cout<<nl;
}

int main(){
    FASTER
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    // }
}



/*
 Same idea for Josephus Problem I, but here k is given, remove the (k+1)th child. Means 1 to K are safe then remove the next untill the n's size is 1.

Using Recursion, its gives TLE for O(n^2) time complexity for erase() function.
Using PBDS, 
    - Here, needs to removes by index, thats why we choose ordered_set here. It gives O(nlogn) time comp.
    - It will find the (k+1)th index which will kill idx = (idx+k) % size, then find their index in sorted order in that ordered_set then it gonna kill and erase it from ordered_set

TC: O(n log n)
SC: O(n)
*/
