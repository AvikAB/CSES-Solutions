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
    vector<tuple<ll,ll,ll>>ranges(n);  // {start, -end, original_idx}
    for(int i=0; i<n; i++){
        ll x,y;
        cin>>x>>y;
        ranges[i] = {x, -y, i};
    }
    sort(ranges.begin(), ranges.end());
    vector<ll>start(n), end(n), idx(n);
    for(int i=0; i<n; i++){
        auto [st, en, id] = ranges[i];
        start[i] = st;
        end[i] = -en;
        idx[i] = id;
    }
    vector<ll>contains(n,0), contained(n,0);

    // contained: sweep left to right, track mxEnd
    ll mxEnd = 0;
    for(int i=0; i<n; i++){
        if(i>0 and end[i]<=mxEnd){
            contained[idx[i]] = 1;
        }
        mxEnd = max(mxEnd, end[i]);
    }

    // contains: sweep right to left, track minEnd
    ll mnEnd = LLONG_MAX;
    for(int i=n-1; i>=0; i--){
        if(i<n-1 and end[i]>=mnEnd){
            contains[idx[i]] = 1;
        }
        mnEnd = min(mnEnd, end[i]);
    }

    for(int i=0; i<n; i++) cout<<contains[i]<<" ";
    cout<<nl;
    for(int i=0; i<n; i++) cout<<contained[i]<<" ";
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
For each range, determine:
    - Does it contain some other range?
    - Is it contained by some other range?
Range [a,b] contains [c,d] iff a ≤ c and d ≤ b.

Obs:
Sort ranges by start ascending, and for equal starts by end descending. Then:
    - Any range after index i has start ≥ start[i], so i contains it iff end[i] ≥ end[j].
    - Any range before index i has start ≤ start[i], so it contains i iff end[j] ≥ end[i].
Sorting ties with larger end first is crucial.

Algo:
    - Sort as {start, -end, original_idx}.
    - Then Contained by:
        - Range i is conatined by something if currEnd<=mxEnd, when i>0.
    - Then Contains:
        - Range i contains something iff currEnd>=mnEnd, when i<n-1.
    - Store ans using original index.

TC: O(n log n)
SC: O(n)
*/
