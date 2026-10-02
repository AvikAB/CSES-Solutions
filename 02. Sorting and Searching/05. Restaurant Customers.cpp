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
    vector<pair<ll,ll>>vp;
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        vp.push_back({a,+1});   // {time, contribute_to_sum}
        vp.push_back({b,-1});
    }
    sort(vp.begin(), vp.end());
    ll sum = 0, mx = 0;
    for(auto &[f, s]:vp){
        sum += s;
        mx = max(mx, sum);
    }
    cout<<mx<<nl;
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
Lets consider arrival time +1 and leaving time -1 for each customers. So we use pair sorting to 
find the maximum amount of arrival times of the customers.
Sum of it at every iteration and keep track the max val of sum.

    2 3  4 5  8  9  -> vp.first
    1 1 -1 1 -1 -1  -> vp.second
    1 2  1 2  1  0  -> sum
    1 2  2 2  2  2  -> mx

TC: O(n log n)
*/
