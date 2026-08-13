// 2D Traversal by DFS
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const ll N = 1e3;
const ll mod = 1e9+7;
const ll INF = 1e9+10;

char grid[N][N];
bool visited[N][N];
ll n, m;

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};

bool isValid(ll nr, ll nc){
    if(nr<0 or nr>=n or nc<0 or nc>=m) return false;

    if(grid[nr][nc]=='#' or visited[nr][nc]) return false;
    return true;
}

void dfs(ll r, ll c){
    visited[r][c] = true;
    for(int i=0; i<4; i++){
        ll nr = r+dx[i];
        ll nc = c+dy[i];
        if(isValid(nr, nc)){
            dfs(nr, nc);
        }
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
            visited[i][j] = false;
        }
    }

    ll cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]=='.' and !visited[i][j]){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout<<cnt<<nl;
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
If we got a floor then cnt it & start dfs from it. Check all 4 sides, if its wall & out of bound then the dfs won't run
for those. And also make a visited array that will track which cell is visited or not, it reduces time & double checking.

TC: O(n*m), SC: O(n*m)
*/
