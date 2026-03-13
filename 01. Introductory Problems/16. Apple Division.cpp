#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll N = 1e7+1234;
const ll mod = 1e9+7;
 
ll ans = LLONG_MAX;
void rec(ll pos, vector<ll>&v, ll sum, ll tot){
    if(pos>=v.size()){
        ll s1 = sum;
        ll s2 = tot-sum;
        ans = min(ans, abs(s1-s2));
        return;
    }
 
    rec(pos+1, v, sum+v[pos], tot);  // pick it
    rec(pos+1, v, sum, tot);        // not pick it
}
 
int main(){
    FASTER
 
    ll n;
    cin>>n;
    ll tot = 0;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
        tot += v[i];
    }
    rec(0, v, 0, tot);
    cout<<ans<<nl;
}


/*
This is a subset sum problem where we need to partition the apples into two groups to minimize the weight difference.

Generate all possible subsets and their sum using recursion. Pick and not pick the element and sum it, whose difference is min take that min element and print it.
*/
