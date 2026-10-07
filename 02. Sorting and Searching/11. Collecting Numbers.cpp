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
    vector<ll>idx(n+1);
    for(int i=1; i<=n; i++){
        ll x;
        cin>>x;
        idx[x] = i;
    }
    ll cnt = 1;
    for(int i=2; i<=n; i++){
        if(idx[i-1]>idx[i]) cnt++;
    }
    cout<<cnt<<nl;
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
Here 1 to n permutation is given, Task is collect the nums from 1 to n in increasing order from the given array's order.

Example: n = 5, [4,2,1,5,3]
    In Round 1: takes 1 only, because the problem says takes 1 to n in increasing order.
    In R-2: takes 2,3.
    In R-3: takes 4, 5.
    So there is total 3 rounds.

So, My first thought was just cnt the decreasing in the given array. And it fails.

So, create a index array & traverse it from left to right. If prev ele is greater than curr ele then we can't
take the ele in the same round, so that new round happens.
So, we can add ele in same round when the next ele is smaller than prev ele.
So, prev > next then cnt it as a new round.

TC: O(n)
SC: O(n)
*/
