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
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<(i^j)<<" ";
        }
        cout<<nl;
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
The question said that for each cell(i,j) contains the smallest number, for this in its above (same col) it doesn't have any smallest number.
For this in its left (same row) also doesn't have any smallest value.

Means the diagonal have only 0 always.
Its easily done by XOR. We need to print grid[i][j]=0, means (0,0),(1,1),(2,2) and so on will be 0.
We know that xor operation is: (same_val^same_val) = 0.
*/
