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
    ll x,n;
    cin>>x>>n;
    set<ll>pos;
    multiset<ll>plens;
    pos.insert(0);
    pos.insert(x);
    plens.insert(x);  // initially, only one passage [0,x]
    for(int i=1; i<=n; i++){
        ll p;
        cin>>p;
        auto itR = pos.upper_bound(p);
        ll R = *itR;
        ll L = *prev(itR);

        // passage in [L,R] splits into two [L,p]+[p,L]
        plens.erase(plens.find(R-L));  // first find then erase else all (R-L) val will remove
        plens.insert(p-L);
        plens.insert(R-p);

        // print max passage length
        cout<<(*plens.rbegin())<<" ";

        pos.insert(p);  // add p[i] to pos
    }
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
Given, the length of streets & num of traffic lights. Print the longest length of path between all active
traffic lights for each input of traffic lights (p[i]).

Example:
x = 8, n = 3, So the road range is [0,8].
p1 = 3, means we put a light in position 3 of that range, then their max difference between the each light is 5 (8-3).
p2 = 6, we put the next light in pos 6, so the mx diff is (6-3) = 3 and (3-0) = 3.
p3 = 2, put the next light in pos 2, so the mx diff is still (6-3) = 3.
So, the output is 5,3,3.

Data_Structure1: Keep track of pos. (set)
Data_Structure2: Keep track of passage_lens. (multiset)

Initially, the range is 0 & x. After a taking a pos, p[i]:
    1. Find L and R in pos. [R = upper_bound(pi) and L=upper_bound(pi)-1]
    2. Remove |R-L| from p_lens.
    3. Add |L-pi| and |R-pi| in p_lens.
    4. Print max of p_lens.
    5. Add p[i] into pos.

TC: O(n log n)
SC: O(n)
*/
