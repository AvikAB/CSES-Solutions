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

ll n,m;
vector<vector<ll>>adj;
vector<ll>team;

bool dfs(ll u){
    for(int v:adj[u]){
        if(team[v]==0){   // no team assigned
            team[v] = 3-team[u];

            if(!dfs(v)) return false;
        } else if(team[u]==team[v]) return false;   // both are same assigned, just like odd-length cycle
    }
    return true;
}

void solve(){
    cin>>n>>m;
    adj.resize(n+1);
    team.resize(n+1, 0);
    for(int i=0; i<m; i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++){
        if(team[i]==0){   // team doesn't assign
            team[i] = 1;
            if(!dfs(i)){
                cout<<"IMPOSSIBLE\n";
                return;
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout<<team[i]<<" ";
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
Here, people -> nodes, friendships -> edges.
Friends are not in same group. There will be total 2 teams 1 & 2.
If u in team-1 then its all neighbour will be in team-2. The problem will be in odd-length cycle.

Let, 1,2,3 nodes are in odd-length cycle. Then 1 in team-1 & its neighbor 2 in team-2 & neighbor 3 in team-2 also.
But neighbor 2 & 3 are also neighbors/friends, so they can't be in same team. For this case, it has no soln.
If 1->2->3->1 is a triangle: 1=team1, 2=team2, 3=team1. But 3 is a neighbor of 1, and both are team1 -> conflict

Here, dfs will return true/false. We make two groups or not. If there are team[i] = 0 means no team assign just make it team[i]=1.

In dfs, neighbor v of u is not assign to a team (team[v]==0) then do team[v]=3-team[u]. It will automatically
toggle its neighbor's team number, if team[u] = 1 then team[v] = 3-team[u] = 3-1 = 2 or if team[u] = 2 then team[v] = 3-team[u] = 3-2 = 1.

Then do dfs of all neighbors of u, if any of them gives false then it return false. Else if u and v are in same assigned team then it return false.

It also contains the bipartite graph theory. (neighbors will be in different set)
*/
