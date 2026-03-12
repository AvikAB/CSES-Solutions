#include<bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define nl "\n"
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e7+1234;
const ll mod = 1e9+7;
 
int main(){
    FASTER
 
    /* Intuition: Trailing zeroes in factorial comes from the factor of 10. since, 10=2*5.
    Every even number contributes a factor of 2. Factors of 5 are less common—they only appear in multiples of 5,10,15 etc.
    So, the number of trailing zeros is determined by how many times 5 appears as a factor in the numbers from 1 to n. 
    Formula to find trailing zeroes: floor(n/5)+floor(n/25)+floor(n/125). That idea is also work for 
    Finding trailing zeros in any product or power: a^b by checking how many times 10(or its factors 2 & 5)divide the number.*/
    
    ll n;
    cin>>n;
    ll cnt = 0;
    while(n/5){
        cnt += (n/5);
        n /= 5;
    }
    cout<<cnt<<nl;
}
