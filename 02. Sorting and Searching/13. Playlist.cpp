// Using set:
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
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    set<ll>lastPos;
    ll ans = 0;
    ll i = 0, j = 0;
    while(i<n and j<n){
        while(j<n and !lastPos.count(v[j])){  // there is no duplicate ele in the curr window
            lastPos.insert(v[j]);
            ans = max(ans, j-i+1);
            j++;
        }
        while(j<n and lastPos.count(v[j])){  // found there a duplicate ele in the curr window, remove it & increment i
            lastPos.erase(v[i]);
            i++;
        }
    } 
    cout<<ans<<nl;
}

int main(){
    FASTER
    // ll t;
    // cin>>t;
    // while(t--){
        solve();
    // }
}


// Using map:
void solve(){
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    map<ll,ll>lastPos;   // id:last_seen_idx
    ll ans = 0;
    ll i = 0, j = 0;
    while(i<n and j<n){
        if(lastPos.count(v[j]) and lastPos[v[j]]>=i){  // found the duplicate inside window
            i = lastPos[v[j]]+1;
        }
        lastPos[v[j]] = j;
        ans = max(ans, j-i+1);
        j++;
    }
    cout<<ans<<nl;
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
Find the longest contiguous subarray with all distinct eles.

Maintain a [i,j]. For each j, if v[j] seen before at pos p>=i then shrink the window by
setting i = p+1. Then update lastPos[v[j]] = j and answer with j+i-1.

Using set/map, TC: O(n log n)
Using custom hashmap, TC: O(n)  
*/
