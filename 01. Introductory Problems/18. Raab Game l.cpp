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
    ll n,a,b;
    cin>>n>>a>>b;
    ll eq = n-a-b;
    if(eq<0){
        cout<<"NO\n";
        return;
    }
    vector<ll>A(n), B(n);

    // A's seq decreasing order (n to 1)
    for(int i=0; i<n; i++){
        A[i] = n-i;
    }

    ll nxtCard = n;
    // equal turns
    for(int i=0; i<eq; i++){
        B[i] = nxtCard--;
    }

    // B wins turns
    for(int i=n-b; i<n; i++){
        B[i] = nxtCard--;
        if(B[i]<=A[i]){   // B must be > A to win
            cout<<"NO\n";
            return;
        }
    }

    // A wins turns
    for(int i=eq; i<n-b; i++){
        B[i] = nxtCard--;  // put almost minimum val in B (check the condition)
        if(A[i]<=B[i]){   // A must be > B to win
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<nl;
    for(int i=0; i<n; i++){
        cout<<B[i]<<" ";
    }
    cout<<nl;
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
n = nums of cards (no. of round), a = wins_of_a, b = wins_of_b are given. Print A's array & B's array as the condition.

Then (n-a-b) are the cases when the round is equal means cards are equal. If (n-a-b)<0 then there is no soln.

Total n turns, with:
*Equal turns where A==B.
*a turns where A>B (A wins)
*b turns where B>A (B wins)

Here, we keep the A's array in descending order (n to 1). We will construct just B array as per the condition.
So we will work for equal turns first, then B's win turn and in last A's win turn. 
Do dry run.
*/
