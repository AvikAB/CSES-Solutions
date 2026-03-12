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
    FASTER
 
    string s;
    cin>>s;
    unordered_map<char,ll> mp;
    for(char c:s){
        mp[c]++;
    }
    ll cnt = 0;  // store the odd cnt of any char
    char ch;
    for(auto av:mp){
        if(av.second%2){  // if freq is odd then increase the cnt
            cnt++;
            ch = av.first;
        }
    }
    if(cnt>1) cout<<"NO SOLUTION\n";
    else {
        string ans = "";
        for(auto av:mp){
            for(int i=1; i<=av.second/2; i++){  // first half, then the odd char then again reverse of this half
                ans += av.first;
            }
        }
        cout<<ans;
        if(s.size()%2) cout<<ch;   // if size is odd then that odd freq's char
        reverse(ans.begin(), ans.end());
        cout<<ans<<nl;
    }
}
 
 
/*
Intuition: No solution occurs when odd length -> if there are 2 char's whose freq is odd,
                even length -> there is char which has odd freq.
            (OR) if odd cnt is more than 1 then its No Solution.
*/
