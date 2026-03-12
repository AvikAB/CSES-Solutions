// The XOR Approach:
#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e7+1234;
const ll mod = 1e9+7;
 
int main(){
    FASTER
 
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    ll xor1 = 0, xor2 = 0;
    for(int i=1; i<=n; i++){
        xor1 ^= i;
    }
    for(int i=0; i<n; i++){
        xor2 ^= v[i];
    }
    cout<<(xor1^xor2)<<nl;
}


// Another Approach:
#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += i;
    }
    for(int i=1; i<=n-1; i++){
        int x;
        cin>>x;
        sum -= x;
    }
    cout<<sum<<"\n";
}
