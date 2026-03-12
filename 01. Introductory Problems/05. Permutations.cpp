#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nl "\n"

int main(){
    ll n;
    cin>>n;
    if(n==1) cout<<"1\n";
    else if(n==2 or n==3) cout<<"NO SOLUTION\n";
    else if(n==4) cout<<"2 4 1 3"<<nl;
    else {
        for(int i=n; i>0; i-=2) cout<<i<<" ";
        for(int i=n-1; i>0; i-=2) cout<<i<<" ";
    }
}



// think about odd-even elements
