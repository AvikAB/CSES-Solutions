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
    ll n,m;
    cin>>n>>m;
    multiset<ll>ms;
    for(int i=0; i<n; i++){
        ll x;
        cin>>x;
        ms.insert(x);
    }
    for(int i=0; i<m; i++){
        ll c;
        cin>>c;
        auto it = ms.upper_bound(c);
        if(it==ms.begin()) cout<<-1<<nl;  // all available are greater than the c
        else {
            it--;
            cout<<*(it)<<nl;
            ms.erase(it);   // can't use that ticket again
        }
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
Goal: For each customer, we want the largest ticket price that is ≤ their maximum willingness to pay.

Just take ticket's input in a multiset (because of same prices can be). Then check the upperbound of customer's willingness pay, if it is
i the begin then there is no nearest value of it, print -1. Else we got the position of that upperbound's value, then one back and print it
and also remove it from the multiset because we can't give same tickets to more customers.

TC: O((n+m)log n)
SC: O(n)
*/
