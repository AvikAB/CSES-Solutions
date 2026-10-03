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
    vector<pair<ll,ll>>vp(n);
    for(int i=0; i<n; i++){
        cin>>vp[i].first>>vp[i].second;    // {start, end}
    }
    sort(vp.begin(), vp.end(), [](auto &a, auto &b){
        return a.second < b.second;     // sort on ending time
    });

    ll cnt = 0, freeAt = 0;
    for(auto &[st, end]:vp){
        if(st>=freeAt){    // if any movie's start time is >= freeAt time then go & watch it
            cnt++;
            freeAt = end;    // that movie's end time will be freeAt time
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
Greedy Approch for Maximum Non-overlapping Intervals

Goal: Max num of movies I can watch entirely. So, I always choose shortest length movie.

Sort on ending time because it gives the shortest length movie first means the min completion time of each movie.
After sort the pair according their ending time, if there is no overlaps then we increase the count means watch the movie.
And freeAt will always update as the ending time of that movie.

TC: O(n log n)
*/
