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
    ll ans = 1;
    for(int i=1; i<=n; i++){
        ans = (ans*2) % mod;
    }
    cout<<ans<<nl;
}
 
int main(){
    // FASTER
    // ll t;
    // cin>>t;
    // while(t--){
         solve();
    // }
}
 
 
 
 
 
/*
There are total 2 ways to choose each bit (0 or 1). So the ans is 2^n
*/
