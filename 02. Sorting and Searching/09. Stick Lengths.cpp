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
    sort(v.begin(), v.end());
    ll mid = v[n/2];
    ll cost = 0;
    for(auto av:v){
        cost += abs(av-mid);
    }
    cout<<cost<<nl;
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
In this problem we are given n nums p1,p2,...,pn & our task is to find a val x that minimizes the sum |x-p1|+|x-p2|+...+|x-pn|.

Choosing best x where it is closest to all p's value. So there is total 2 choices: 1. Median, 2. Mean (Avg).

- The median minimizes the sum of absolute diffs.
- The mean minimizes the sum of squared diffs (but not absolute).  (sum(p[i]-x)^2)
So, optimal choice is taking median.

For median, there will be 2 cases. Odd & Even n. When n is odd then mid = (n/2).
When n is even then there is 2 median, m1 & m2. m1 = (n/2), m2 = (n+1/2), here m1 and m2 not differ any major changes here.
So, we can use mid = (n/2) for both, odd or even n.

TC: O(n log n)
*/
