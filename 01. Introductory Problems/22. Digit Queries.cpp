// Method 1: Using Maths
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

char kthdigit(ll k){
    ll m = 1;     // the num of dig in the curr group (1dig, 2dig, 3dig,...)
    ll cnt = 9;  // total nums in the curr group (9 for the 1st group)
    ll start = 1; // first num in the curr group (for 1st grp:1, 2nd grp:10,3rd grp:100...)
    while(k>m*cnt){
        k -= m*cnt;
        m++;
        cnt *= 10;
        start *= 10; 
    }
    ll num = start+(k-1)/m;
    ll digpos = (k-1)%m;
    return to_string(num)[digpos];  // num[digpos]
}

void solve(){
    ll q;
    cin>>q;
    while(q--){
        ll k;
        cin>>k;
        cout<<kthdigit(k)<<nl;
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
Method 1: Using Maths
1. Number length groups: The number can be grouped based on their digit length.
    1-dig nums: 1 to 9 (9 nums, contributing 9*1=9 digs)
    2-dig nums: 10 t0 99 (90 nums, contributing 90*2=180 digs are 2-dig num)
    3-dig nums: 100 to 999 (900 nums, contributing 900*3=2700 digs are 3-dig num)
    and so on...
2. Finding the correct group: For a given k, we need to determine which group (based on dig len) the k-th digs fall into.
    1. Subtracting the total digs contributed by all smaller groups from kuntill k falls within the curr group.
    2. The rem k will help us find the specific num within the group & the exact dig within that num.

    Example: k=300, 1st group has 9 digs, 300-9=291, 2nd group has 180digs, 291-180=111, so 111 position stands in 2nd group.
3. Locating the number & digit: We will a start variable that points to the start of the group. Then, the number we need is: start+(k-1)/m. here, m = len of group.
    
    Example: 10 11 12 13 14 15 16 17 18 19 20, k=10
    Since, each num is len of m (here 2). So to reach correct num we will just do (k-1)/m & add it to start. (k-1 for 0-based indexing)
    For the example, num = 10+(10-1)/2.
    The digit inside it is: (k-1)%m.
        digpos = (k-1)%m = (10-1)%2 = 1, means 10th pos val is 14, here idx '0'=1 and idx '1'=4. So, 4 will be ans.
TC: O(logk)
SC: O(1)
*/


// Method 2: Using Binary Search:

/*
Method 2: Using Binary Search

*/
