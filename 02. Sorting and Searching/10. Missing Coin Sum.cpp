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
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    ll sum = 0;
    for(int ele:v){
        if(ele>sum+1) break;
        sum += ele;
    }
    cout<<(sum+1)<<nl;
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
Greedy Method:
From the array element, we can create the range of sums [ele, sum+ele].
here, sum+ele is actually a new sum for next ele. If there a gap between the ranges, we can't create
the gap, the gap is the answer. 
For a ele x, x>(sum+x+1), then (sum+x+1) is the gap, it can't be formed.

Example:
    [2,9,1,2,7] = After sorting = [1,2,2,7,9]
    sum = 0
    For ele 1, The range is: [1, 0+1] = [1,1]
    For ele 2, The range is: [2, 1+2] = [1,3]
    For ele 2, The range is: [2, 3+2] = [2,5]
    For ele 9, The range is: [9, 5+9] = [9,14], here we got a gap, this gap is the smallest sum.
So, the gap will be (sum+ele+1) = (3+2+1) = 6

TC: O(n log n)
SC: O(1)
*/
