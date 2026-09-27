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
    ll n,x;
    cin>>n>>x;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll l = 0, r = n-1;
    ll ans = 0;
    while(l<=r){
        if(v[l]+v[r]>x){
            ans++;
            r--;
        } else {
            ans++;
            l++, r--;
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



/*
Easy Two Pointer approach. Sort it, put 1 pointer in the beginning and other one in the end.
If their sum is larger than the x then we need a gondola for the heavy wighted child and move r in the left.
If their sum is smaller and equal to x then also need a gondola for them and check more with l++ & r--.
*/
