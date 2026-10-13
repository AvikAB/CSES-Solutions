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

    // contained by:
    ordered_set<pair<ll,ll>>os1;
    ll c1 = 0;
    for(int i=0; i<n; i++){
        ll less = os1.order_of_key({end[i], -1});   // strickly less than end[i], <end[i]
        contained[idx[i]] = os1.size()-less;      // >=end[i]
        os1.insert({end[i], c1++});
    }

    // contains:
    ordered_set<pair<ll,ll>>os2;
    ll c2 = 0;
    for(int i=n-1; i>=0; i--){
        // count of elements<=end[i] = order_of_key(end[i]+1, -1)
        contains[idx[i]] = os2.order_of_key({end[i]+1, -1});
        os2.insert({end[i], c2++});
    }

    for(int i=0; i<n; i++) cout<<contains[i]<<" ";
    cout<<nl;
    for(int i=0; i<n; i++) cout<<contained[i]<<" ";
    cout<<nl;
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
Same for the previous problem, just it needs to count the contains and contained by.
Range [a,b] contains [c,d] if a<=c and d<=b.

Obs:
Sort ranges by start ascending, and for equal starts by end descending. Then:
    - Any range after index i has start ≥ start[i], so i contains it iff end[i] ≥ end[j].
    - Any range before index i has start ≤ start[i], so it contains i iff end[j] ≥ end[i].
Sorting ties with larger end first is crucial.

Algo:
    - Sort as {start, -end, original_idx}.
    - Then Contained by:
        - Range i is conatined by something if currEnd<=mxEnd, when i>0.
        - contained[i]: count of j<i with end[j]>=end[i].
    - Then Contains:
        - Range i contains something iff currEnd>=mnEnd, when i<n-1.
        - contains[i]: count of j>i with end[j]<=end[i].
    - Store ans using original index.

* Here, used pair for track the same value for end[i], we can use multiset here.

TC: O(n log n)
SC: O(n)

count/no. of  :    use
elements < x  :   order_of_key(x)
elements <= x :   order_of_key(x+1)
elements >= x :   size() - order_of_key(x)
elements > x  :   size() - order_of_key(x+1)
*/
