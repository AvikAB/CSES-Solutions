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
 
char board[8][8];
 
bool isSafe(ll x, ll y, ll n){
    // for column
    for(int i=0; i<x; i++){
        if(board[i][y]=='Q') return false;
    }
    // for upper-right diagonal
    ll i = x, j = y;
    while(i>=0 and j<n){
        if(board[i][j]=='Q') return false;
        i--;
        j++;
    }
    // for upper-left diagonal
    i = x, j = y;
    while(i>=0 and j>=0){
        if(board[i][j]=='Q') return false;
        i--;
        j--;
    }
    return true;
}
 
ll cntNqueen(ll row){
    if(row==8) return 1;
    ll total = 0;
    for(int col=0; col<8; col++){
        if(board[row][col]=='*') continue;
        if(isSafe(row, col, 8)){
            board[row][col] = 'Q';
            total += cntNqueen(row+1);
            board[row][col] = '.';
        }
    }
    return total;
}
 
int main(){
    FASTER
 
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cin>>board[i][j];
        }
    }
    cout<<cntNqueen(0)<<nl;
}



/*
Classic N queens problem using recursion and backtracking.
*/
