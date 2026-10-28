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
    vector<tuple<ll,ll,ll>>cust(n);   // {arrival, departure, id}
    for(int i=0; i<n; i++){
        ll a,b;
        cin>>a>>b;
        cust[i] = {a,b,i};
    }
    sort(cust.begin(), cust.end());
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> mnHeap;   // {departure, room}
    vector<ll>roomOf(n);
    ll tot = 0;
 
    for(auto [arrival, departure, id]:cust){
        ll room;
        if(!mnHeap.empty() and mnHeap.top().first<arrival) {
            room = mnHeap.top().second;  // reuse the early free room
            mnHeap.pop();
        } else {
            room = ++tot;
        }
        roomOf[id] = room;
        mnHeap.push({departure, room});
    }
 
    cout<<tot<<nl;
    for(int i=0; i<n; i++){
        cout<<roomOf[i]<<" ";
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
Smallest end time < curr arrival time -> we can assign same room.
Sort by arrival times in ascending order. Using min Heap for that.
Track the end_time (also update smallest end_time).
    if(smallest end_time < curr_arrival_time)
        then_same_room.
    else
        new_room.

In heap:
We will check it in loop, because multiple rooms can be free after the last customer.
Means free all rooms in heap whose customer has left (same arrival & departure time can be occured).
Then after the loop:
    1. If heap is empty -> new_room
    2. else -> reuse heap.top().room_id.
*/
