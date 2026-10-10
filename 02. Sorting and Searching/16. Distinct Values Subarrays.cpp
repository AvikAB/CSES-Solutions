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
    ll ans = 0;
    map<ll,ll>mp;
    ll i = 0, j = 0;

    while(j<n){
        mp[v[j]]++;   // add curr ele in the map
        while(mp[v[j]]>1){  // while a duplicate ele is present, shrink window from left
            mp[v[i]]--;
            if(mp[v[i]]==0){
                mp.erase(v[i]);
            }
            i++;
        }
        ans += (j-i+1);
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
Given n and n sized array. Count the num of subarray's whose all eles are unique.

Approach:
Using Two Pointer and map for track the uniqueness.
i = 0, j = 0, total = 0
  1. Expand window from right one by one.
  2. Shrink the window from left untill [i,j] has all unique eles. For checking unique eles, we
      will use map here for the window.
  3. total += (j-i+1) for each iteration.  

TC: O(n*log n)
SC: O(n)
*/
