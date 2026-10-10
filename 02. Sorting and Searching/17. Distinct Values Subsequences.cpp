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
    
    ll ans = 1;
    map<ll,ll>mp;  // {num, freq}
    for(int i=0; i<n; i++){
        mp[v[i]]++;
    }

    for(auto &[num,freq]:mp){
        ans *= (freq+1);
        ans %= mod;
    }
    cout<<(ans-1)<<nl;  
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
Given n and n sized array. Count the num of subseqs whose all eles are unique.

Approach:
Total num of subseq = (2^n)-1. Because of each ele has 2 choices (present in subseq, not present in subseq).
[-1 for empty subseq].

Let, we have a array where 'a' present fa times (fa = freq of 'a'), b presents fb times & c presents fc times.
So, for 'a' be the part of subseq there is total fa+1 choices. Same for b and c.

-> How?
Let, we have "aaaa", so we have total fa+1 = 4+1 = 5 choices. We can select here 1st 'a' or 2ns 'a' or 3rd 'a' or 4th 'a' or
none of them (subseq without 'a').

So, the num of subseqs with distinct eles = product of (f[i]+1) - 1.
Here, -1 for empty subseq means we not add any ele in the subseq.

TC: O(n*log n)
SC: O(n)
*/
