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
    ll sum = 0, mx = LLONG_MIN;
    for(int i=0; i<n; i++){
        sum += v[i];
        mx = max(mx, sum);
        if(sum<0) sum = 0;  // new segment start from next ele
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
If the sum is increased then we add the value to sum otherwise just take the value. Print the maximum sum.

Using Kadane's Algo. Just check the sum and increase the length of subarray. If negative sum val occurs then
restart the new subarray with the next ele.

TC: O(n), SC: O(1)
*/
