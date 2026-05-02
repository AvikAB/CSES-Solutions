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

vector<pair<ll,ll>>moves = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,1}, {-2,-1}, {-2,1}, {2,-1}};

bool isValid(ll row, ll col, ll n){
    return row>=0 and row<n and col>=0 and col<n;
}

void BFS(vector<vector<ll>>&grid, pair<ll,ll>start, ll n){
    queue<pair<ll,ll>>q;
    q.push(start);

    ll u = start.first;
    ll v = start.second;
    grid[u][v] = 0;   // top left cell (0,0)=0

    while(!q.empty()){
        u = q.front().first;
        v = q.front().second;
        q.pop();

        for(auto av:moves){
            ll i = u+av.first;
            ll j = v+av.second;
            if(isValid(i,j,n) and grid[i][j]==-1){
                grid[i][j] = grid[u][v]+1;   // new grid
                q.push({i,j});
            }
        }
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<vector<ll>>grid(n, vector<ll>(n,-1));
    BFS(grid, {0,0}, n);

    for(int i=0; i<n; i++){
        for(int j=0;j<n; j++){
            cout<<grid[i][j]<<" ";
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
Knight movement is 'L' shaped. A knight's highest movement is 8 from a cell (i,j).
The movements are {x,y} = {1,2}, {1,-2}, {-1,2}, {-1,-2} [basis on vertical-y axis]
                  {x,y} = {2,1}, {-2,-1}, {-2,1}, {2,-1} [basis on horizontal-x axis]

Print: grid[i][j] = min num of moves to reach (0,0) from (i,j).

Now, we can say that, from (i,j) to (0,0)'s move is x
                then, from (0,0) to (i,j)'s move is also x.

Approach:
So, first step is from (0,0) go to that cell which is 'L' shaped and from that cell to (0,0)
the min move is 1.
So, for (0,0), the first step of 'L' shaped are placed at (1,2) and (2,1). So, we can say that from (1,2)
and (2,1), we need just 1 step to go (0,0) where the movement is 'L' shape.

Now, from (1,2) and (2,1), each cell will move one step forward to that cell and then from the new cell to (0,0)'s
move will be 2.

For (1,2), we can go basis on 'L' shaped at (2,0), (3,1) and (3,3).
For (2,1), we can go basis on 'L' shaped at (0,2), (3,3) and (1,3).

From this we can said that,
    (0,0)  ---1step--> (1,2),(2,1) ---2steps---> (2,0), (3,1), (3,3), (0,2), (1,3), (3,3)
So, that cell will store the min moves of this.

So, the new cells are like that: grid[x'][y'] = grid[x][y]+1.

Now, the same approach used for 2 step's cells. From that 2 step's cell will try to go next
cell basis on 'L' shape.

Example:
From (0,0) to (0,2) needs 2 steps to go there. Now, from (0,2) to 'L' shaped cells are (1,0),
(1,2),(1,3), these are the new cell where the moves=3 to go (0,0) cell. Now, here the (1,2)
is already visited, from this (1,2) to (0,0)'s min move is 2. So, grid[1][2] = 2, not 3.

Same for the step=4,5,6 and so on.

Using queue to solve this problem. Also using BFS knowldge in that.
At first take {0,0} in the queue and pop it & explore all neighbors of it which has step=1 
and basis on 'L' shape.
Also add their neighbor to the queue. And do the same stuffs as always.
When explore the added cell of the queue then pop it while processing it and add the all possible neighbors
to the queue.

TC: O(n*n*8)
SC: O(n*n)
*/
