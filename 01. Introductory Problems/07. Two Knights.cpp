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
    for(int k=1; k<=n; k++){
        ll totCells = k*k;
        if(n==1) cout<<0<<nl;
        else {
            ll totPlace = (totCells*(totCells-1))/2; // k^2c2
            ll attackingPlace = 4*(k-2)*(k-1);
            ll ans = totPlace - attackingPlace;
            cout<<ans<<nl;
        }
    }
}
 
int main(){
    // FASTER
    // ll t;
    // cin>>t;
    // while(t--){
         solve();
    // }
}
 
 
 
 
 
/*
Total Placements is k^2 c 2 = ((k^2)*(k^2-1))/2; From k^2 choose any 2 distinct cells.
 
Knights moves for (r,c) = (+-2, +-1) and (+-1, +-2).
 
For every (2,1) moves in cell,
    1<=r<=k           1<=c<=k
  =>1<=r+2<=k       =>1<=c+1<=k
  =>1<=r<=(k-2)     =>1<=c<=(k-1)
 
So, (k-2) choices for rows, (k-1) choices for cols.
So, choices is (k-2)*(k-1).
 
There are total 8 possible knight moves from (r,c): (2,1), (2,-1), (-2,1), (-2,-1), (1,2), (1,-2), (-1,2), (-1,-2).
For every moves same choices (k-2)*(k-1). So, total choices = 8*(k-2)*(k-1).
 
Now, for two knights choose 2 distinct cells, thats why, total choices = 8*(k-2)*(k-1) / 2 => 4*(k-2)*(k-1).
Total choices means attacking placements.
 
    ans = total placements - attacking placements
 => ans = (k*k)c2 - 4*(k-2)*(k-1)
 => ans = k^2(k^2-1)/2 - 4*(k-2)*(k-1)
 
Thats the number of ways two knights can be placed on a k*k chessboard.
*/
