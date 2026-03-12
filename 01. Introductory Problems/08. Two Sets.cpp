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
 
    ll n;
    cin>>n;
    ll sum = n*(n+1)/2;
    vector<ll>s1, s2;
    if(sum%2) cout<<"NO\n";
    else {
        cout<<"YES\n";
        ll mid = sum/2;
        for(int i=n; i>=1; i--){
            if(i<=mid){
                s1.push_back(i);
                mid = mid-i;
            } else s2.push_back(i);
        }
 
        cout<<s1.size()<<nl;
        for(auto av:s1){
            cout<<av<<" ";
        }
        cout<<nl;
 
        cout<<s2.size()<<nl;
        for(auto av:s2){
            cout<<av<<" ";
        }
        cout<<nl;
    }
}


/*
We can calculate the sum of numbers using the well-known formula $$s = 1+2+\dots+n = \frac{n(n+1)}{2}.$$

If s is odd, it is clearly not possible to solve the problem. However, if s is even, we can always solve the problem using a greedy algorithm.
We go through the numbers from n to 1 and create two sets that both have sum s/2. We add a number x to the first set if the sum of numbers in the first set after adding x is at most s/2. Otherwise, we add x to the second set. Finally, we have processed all numbers and both sets have sum s/2.
Why does the algorithm work? In fact, the algorithm can create any sum between 0 and 1+2+\dots+n using the numbers \{1,2,\dots,n\} and we can prove it as follows using induction.
Case n=1: We can clearly create both sums 0 and 1 using the algorithm.
Case n=k: We want to create a sum a where 0 \le a \le 1+2+\dots+k using the numbers \{1,2,\dots,k\}. If a \ge k, we use k in the sum and then create a sum a'=a-k using the numbers \{1,2,\dots,k-1\}. Otherwise a<k and we create a sum a'=a using the numbers \{1,2,\dots,k-1\}. In both cases 0 \le a' \le 1+2+\dots+k-1, so the algorithm works.
Since s/2 is between 0 and s, we can use the algorithm to solve the problem.

*/
