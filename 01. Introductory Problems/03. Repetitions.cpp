#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define ll long long
#define nl "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <typename T> using ordered_set = tree<T,null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
const ll N = 1e5+10;
const ll mod = 1e9+7;
const ll INF = 1e9+10;
 
int main(){
    FASTER
 
    string s;
    cin>>s;
    ll ans = 0, cnt = 1;
    for(int i=1; i<s.size(); i++){  // loop starts from 1st index thats why cnt = 1 for 0th idx
        if(s[i]!=s[i-1]){  // if prev and curr are not equal then find the max of ans & curr cnt
            ans = max(ans, cnt);
            cnt = 1;  // cnt will start from 1
        } else cnt++;
    }
    ans = max(ans, cnt);
    cout<<ans<<nl;
}
