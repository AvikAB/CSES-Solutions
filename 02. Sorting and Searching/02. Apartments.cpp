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
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>a(n), b(m);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll i = 0, j = 0;
    ll cnt = 0;
    while(i<n and j<m){  // i for applicants, j for appartments
        if(b[j]<a[i]-k){     // small appartments, try next appartments
            j++;
        } else if(b[j]>a[i]+k){    // big appartments, this applicant no need this, try next applicant
            i++;
        } else {   // appartments within range
            i++, j++;
            cnt++;
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
Goal: Assign as many appartments as possible to the candidates by their choices.

Algo:
1. Sort both arrays in ascending order.
2. Use two pointers: one for applicants (a), one for apartments (b).
3. For each applicant (in sorted order), find the smallest apartment that satisfies their requirement.
   - If appartment is small then their lowest desired size then move to the next appartment.
   - If appartment is big then their highest desired size then no need this appartment to the applicants, try next people.
   - If appartment is in range then assign it to the current people.

TC: O(nlogn+mlogn), for sorting (nlog n)+(mlogn)
SC: O(1)
*/
