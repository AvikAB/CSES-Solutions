// Main Josephus Problem & its logic:
// n, k given, every kth person will die (k-1).

// Recursive Way (O(n^2)):
void josephus(vector<ll>&v, ll k, ll idx){
    if(v.size()==1){    // base case
        cout<<v[0]<<nl;  // safe place
        return;
    }

    // find index of person to kill
    idx = (idx+k-1) % v.size();
    cout<<v[idx]<<" ";

    // remove the killed person
    v.erase(v.begin()+idx);

    josephus(v, k, idx);
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    ll idx = 0;   // starting idx
    josephus(v, k, idx);
}

/*
TC: O(n^2), because of erase() function.
This problem define in recursively. Each and every round there will reduce n-1 people untill n = 1.

The game starts with 0th index, means with the 1st people. Here, people's order (1,2,...) will not change, just change their index.
And always the removed person will be idx = (idx+k-1) % size.

Base Case: if(size==1) return; or we got the safe place.
*/


// CSES Problem:
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
    ordered_set<ll>s;
    for(int i=1; i<=n; i++){
        s.insert(i);
    }
    ll idx = 0;
    while(!s.empty()){
        idx = (idx+1) % s.size();   // every people will remove their next one
        auto it = s.find_by_order(idx);  // give me the ele in the position idx in sorted order
        cout<<*it<<" ";
        s.erase(it);
    }
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
Here it says, n people is given. Every other will remove the next one. Means 1 will remove 2, 3 will remove 4 and so on.

Using Recursion, its gives TLE for O(n^2) time complexity for erase() function.
Using PBDS, 
    - Here, needs to removes by index, thats why we choose ordered_set here. It gives O(nlogn) time comp.
    - It will find the next one which will kill idx = (idx+1) % size, then find their index in sorted order in that ordered_set then it gonna kill and erase it from ordered_set

TC: O(n log n)
SC: O(n)
*/
