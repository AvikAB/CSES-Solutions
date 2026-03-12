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
    ll a,b;
    cin>>a>>b;
    bool ok = false;
    if((2*a-b)%3==0){      // check for y
        ll y = (2*a-b)/3;
        if(y>=0 and (b-y)%2==0){   // check for x
            ll x = (b-y)/2;
            if(x>=0) ok = true;
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
}
 
int main(){
    FASTER
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
 
 
 
 
 
/*
There are total 2 moves. We can represent them by: x+2y = a ,.....(1)
                                                   2x+y = b ,.....(2)
 
(1*2) - 2 -> 2x+4y = 2a
             -2x-y = -b
        --------------------
                3y = 2a - b
              => y = (2a - b) /3
 
Now, from (2), x = (b-y)/2.  We should find y earlier then find x.
 
Assume that we will go (a,b) from (0,0).
In code, at first check y then check x and if both are greater than or equal to 0 then YES.
*/




// Another Approach:

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
    ll a,b;
    cin>>a>>b;
    if((a+b)%3==0 and a<=2*b and b<=2*a) cout<<"YES\n";
    else cout<<"NO\n";
}
 
int main(){
    FASTER
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
 
 
 
 
 
/*
Since each move removes three coins, the total number of coins must be divisible by three.
Each move removes at least one coin from each pile, so the number of coins in a pile must be at most twice the number of coins in the other pile.
If the above conditions hold, we can always empty the piles using a greedy algorithm that removes two coins from the pile that has more coins. If both piles have the same number of coins, we can arbitrarily select the move.
*/
