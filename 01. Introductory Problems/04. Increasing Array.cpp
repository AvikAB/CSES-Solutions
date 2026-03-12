#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define nl "\n"
 
const int mx = 2e5+1234;
 
int main(){
    ll n;
    cin>>n;
    ll a[mx];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll cnt=0;
    for(int i=1; i<n; i++){
        if(a[i]<a[i-1]){
            cnt+=(abs(a[i]-a[i-1]));
            a[i] = a[i-1];
        }
    }
    cout<<cnt<<nl;
}


/*
Editorial:
If we think from left to right:
  At position i, we want a[i] >= a[i-1].
  If a[i] is already >= a[i-1], we don't need to change a[i].

If a[i] is less than a[i-1], we must increase a[i] to at least a[i-1].
But we can increase it only to a[i-1] exactly — no point going higher, because that might create problems later for no benefit.

So:
Rule: When a[i] < a[i-1],
Increase a[i] to a[i-1]
Moves needed = a[i-1] - a[i] (which is positive)
Add that to total moves
Update a[i] to a[i-1] in our array for future comparisons

*/
