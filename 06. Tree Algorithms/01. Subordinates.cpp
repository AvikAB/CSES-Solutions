// The num of children in its subtree

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

ll n;
vector<vector<ll>>adj;
vector<ll>sub;

void dfs(ll node){
    sub[node] = 0;
    for(ll child:adj[node]){
        dfs(child);
        sub[node] += sub[child]+1;
    }
}

void solve(){
    cin>>n;
    adj.resize(n+1);
    sub.resize(n+1, 0);
    for(int i=2; i<=n; i++){  // tree creation
        ll boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    dfs(1);
    for(int i=1; i<=n; i++){
        cout<<sub[i]<<" ";
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
1 - is the director of the company.
Remaining given n-1 are their direct boss of the company to its idx employees.
Input:
    n = 5
    arr = 1 1 2 3
    idx = 2 3 4 5

    Its means 2's boss is 1, 3's boss is 1, 4's boss is 2 and 5's boss is 3. Its create a tree with the root node of 1.

Output:
    idx = 1 2 3 4 5
    arr = 4 1 1 0 0

    Its means 1's under there are total 4 employees (2,3,4,5). 2's under 1 employee(4), 3's under 1 employee(5).
    4 & 5's under 0 employees.

So, 1 is the root. 1-indexed array says that its index's parent is a[i].
Means i is the child of arr[i].

*Starts with the leaf node. Each leaf node will send their (subordinate+1) to their parent node.
So, each child reply with (How many employees in his under + himself) to its parent.

Using DFS for traverse the tree. Using DFS, then it will not enough to be parent < child pattern.
We just compute subtree sizes bottom-up (post order).

The approach is:
    a. Build the tree where employee i is a child of arr[i].
    b. Use DFS to traverse from root (employee 1).
    c. Compute subtree sizes bottom-up (post-order).
    d. Each node sends (subordinates + 1) to its parent.

TC & SC: O(n)
*/
