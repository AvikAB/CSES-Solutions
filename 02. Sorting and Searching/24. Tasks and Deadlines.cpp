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
    vector<pair<ll,ll>>v(n);    // {duration, deadline}
    for(int i=0; i<n; i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(), v.end());
    ll totReward = 0;
    ll timeSum = 0;    // where we get all task's finish time, ft = currTime + duration
    for(int i=0; i<n; i++){
        timeSum += v[i].first;     // add duration
        totReward += (v[i].second - timeSum);   // deadline-timesum
    }
    cout<<totReward<<nl;
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
We have n tasks, each with duration 'a' & 'd'. Reward for a task = (d-f) where f is finishing time.
    Total Reward = summation(d[i]-f[i])
                 = summation(d[i]) - summation(f[i])

    Here, d[i] is fixed (its given), we need to minimizes summation(f[i]). (need to calc f[i])

To minimize the sum of finishing times, works with the duration in increasing order. Means short duration time first.

Example:
        ------|------|-------|---->
        0     5      11      19         -> t = finishing time of all tasks

    So, I complete the 1st task within time=5, 2nd task within t=11, 3rd task within t=19.

1st task deadline(dl) was 12 & I finished at 5, so reward = (12-5), 2nd task dl=10, I completed it in 11, reward = (10-11),
3rd task dl=15, but I completed in t=19, reward = (15-19).

Total Rewards = (12-5)+(10-11)+(15-19) = 7-1-4 = 2.

Algo:
    1. Sort duration in ascending order.
    2. Time starts with 0, timeSum will be += duration, it will gives finishing time of all tasks.
    3. Find the reward (deadline-timeSum).


TC: O(nlogn), SC: O(1)
*/
