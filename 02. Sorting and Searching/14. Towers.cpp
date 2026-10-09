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
    multiset<ll>top;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        auto it = top.upper_bound(x);  // smallest val > x
        if(it==top.end()) top.insert(x);  // not present just add a new tower
        else {      // if present then remove the prev top & x will be new top
            top.erase(it);  
            top.insert(x);
        }
    }
    cout<<top.size()<<nl;
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
For a ele x:
    1. Find the smallest top that is > x (using upperbound on sorted arr)
    2. If its found then x will be new top of the existing tower.
    3. If not found then x will be top of the new tower.

TC: O(n log n)
SC: O(n)
*/
