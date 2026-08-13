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

vector<ll>adj[N];
bool vis[N];

void dfs(ll node){
    vis[node] = true;
    for(ll child:adj[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
}

void solve(){
    ll n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<ll>comp;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            comp.push_back(i);
        }
    }
    cout<<(comp.size()-1)<<nl;
    for(int i=0; i<comp.size()-1; i++){
        cout<<comp[i]<<" "<<comp[i+1]<<nl;
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
Count connected components, the needed road will be connected_comp - 1. Also store the starting node of dfs as the new roads which will be connect.
TC: O(n+m), SC: O(n+m)
*/
