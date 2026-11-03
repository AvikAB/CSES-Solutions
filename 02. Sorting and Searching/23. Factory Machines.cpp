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

bool check(ll mid, vector<ll>&v, ll t){
    ll tot = 0;
    for(int i=0; i<(int)v.size(); i++){
        tot += (mid/v[i]);
        if(tot>=t) return true;  // check here because after loop tot will be very high
    }
    return false;
}

void solve(){
    ll n,t;
    cin>>n>>t;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll lo = 0, hi = v[n-1]*t;
    ll ans = hi;
    while(lo<=hi){
        ll mid = (lo+hi)/2;
        if(check(mid, v, t)){
            ans = mid;
            hi = mid-1;
        } else lo = mid+1;
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
Can I guess a time x & check if x is enough to produce atleast k items?
Yes, classic Binary Search on answer (time).
 
If a machine can complete produces K products on x time, then its obviously can produces x+1, x+2,...etc time.
The question says minimum time to make all t products, so, I need to find first true val of it.
 
Checker func: Let, we pick a time t(mid).
    Products made by machine i = floor(t/a[i]).
    Total products will be: tot(t) = summation of i=1 to n (t/a[i]).
 
Search space:
lo = 1, because time can't be 0 sec.
hi = max(arr[i])*t; worst case: only the slowest machine produces everything.
For a test case, it will take atmost max(arr[i])*t time to make all products.
Total searchspace is 10^18. Because max(arr[i]) can be 10^9 in worst case & t can be 10^9 in worst case.

TC: O(n log m), where m is searchspace (10^18).
SC: O(1)
*/
