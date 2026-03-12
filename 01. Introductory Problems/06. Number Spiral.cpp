#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e7+1234;
const ll mod = 1e9+7;
 
int main(){
    FASTER
 
    ll t;
    cin>>t;
    while(t--){
        ll row,col;
        cin>>row>>col;
        ll diag = max(row,col);
        ll diag_ele = diag*diag-diag+1;  // diagonal=(n^2)-n+1
 
        /*
        from the given table, if diag is odd then row-wise decrement & col-wise increment
        if diag is even then the opposite of odd case, then row-wise increment & col-wise decrement.
        here, col & row wise increment and decrement depends on their row,col values.
        */
        if(diag&1){
            if(row>col) cout<<diag_ele - (row-col)<<nl;
            else cout<<diag_ele + (col-row)<<nl;
        } else {  // else diag is even
            if(row<col) cout<<diag_ele - (col-row)<<nl;
            else cout<<diag_ele + (row-col)<<nl;
        }
    }
}
