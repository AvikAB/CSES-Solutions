// Method 01: Two Pointer
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll N = 1e7+1234;
const ll mod = 1e9+7;
 
int main(){
    FASTER;
 
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,ll>>v(n);  // {ele, idx}
    for(int i=0; i<n; i++){
        cin>>v[i].first;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());
    ll l=0, r = n-1;
    while(l<r){
        ll sum = v[l].first+v[r].first;
        if(sum==x){
            cout<<v[l].second<<" "<<v[r].second<<nl;
            return 0;
        } else if(sum>x) r--;
        else l++;
    }
    cout<<"IMPOSSIBLE\n";
}


/*
Basic two pointer technique-If the sum is greater than x the upper pointer should be decreased or
if less than x then lower pointer should be increased. Here we need to use pair to store the indices of the value.

TC: O(n log n) for sorting
*/

// Method 02: Using hashmap
int main(){
    ll n,x;
    cin>>n>>x;
    map<ll,ll>mp;   // {val, idx)
    ll idx1 = -1, idx2 = -1;
    for(int i=0; i<n; i++){
        ll p;
        cin>>p;
        if(mp[x-p]){
            idx1 = mp[x-p], idx2 = i+1;
            break;
        } else mp[p] = i+1;
    }
    
    if(idx1==-1) cout<<"IMPOSSIBLE\n";
    else cout<<idx1<<" "<<idx2<<nl;
}

/*
Take the array's val as n times p. In map takes {val, idx}, no need to sorting because map is automatically sort it. Just check (target-val) is present in map, if it
is present then its value will be an index and other index will be current i. If it is not present then just input in the map as [val] = {idx}, here idx is value of val.

If any idx remains -1 then it is not possible.

TC: O(n log n), total n iterations and each iteration take O(log n) for insert into map.
*/
