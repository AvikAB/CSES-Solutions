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

set<string>perm;

void permutations(string pref, string suff){
    if(suff.size()==0){
        perm.insert(pref);
        return;
    }

    for(int i=0; i<suff.size(); i++){
        permutations(pref+suff[i], suff.substr(0, i)+suff.substr(i+1));  // means add a char "suff[i]" to pref and remove suff[i] from suffix
    }
}

void solve(){
    string s;
    cin>>s;
    permutations("", s);
    cout<<perm.size()<<nl;
    for(auto av:perm){
        cout<<av<<nl;
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
The size will be formula of permutations-repeatations (n!/repeat!).

This is classical recursive problem. Let, you have a box of letters. You need to
arrange them in every possible order.
Example: abc -> abc, acb, bac, bca, cab, cba.

Here, in code, permutations(" ", "abc"); means prefix=" ", suffix="abc".
How it works:
1. Take one character from suffix & moves it to prefix.
2. Recursively repeats with remaining chars.
3. Stops when suffix is empty (all chars used).

Example:  pref = " ", suff = "abc"
1. Take 'a' -> pref="a", suff="bc"
     Take 'b' -> pref="ab", suff="c"
     Take 'c' -> pref="abc", suff=" " -> "abc" taken

     Take 'c' -> pref="ac", suff="b"
     Take 'b' -> pref="acb", suff="" -> "acb" taken

2. Take 'b' -> pref="b", suff="ac"
     Take 'a' -> pref="ba", suff="c"
     Take 'c' -> pref="bac", suff="" -> "acb" taken

     Take 'c' -> pref="bc", suff="a"
     Take 'a' -> pref="bca", suff="" -> "bca" taken

3. Take 'c' -> pref="c", suff="ab"
     Take 'a' -> pref="ca", suff="b"
     Take 'b' -> pref="cab", suff="" -> "cab" taken

     Take 'b' -> pref="cb", suff="a"
     Take 'a' -> pref="cba", suff="" -> "cba" taken

Use diagram for it.
*/
