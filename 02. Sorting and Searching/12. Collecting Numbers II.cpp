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
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n+1), pos(n+1);
    for(int i=1; i<=n; i++){
        cin>>v[i];
        pos[v[i]] = i;
    }
    ll r = 1;   // round
    for(int i=2; i<=n; i++){
        if(pos[i-1]>pos[i]) r++;
    }
    while(m--){
        ll i,j;
        cin>>i>>j;
        if(i>j) swap(i,j);
        ll x = v[i];
        ll y = v[j];
        if(pos[x+1]>i and pos[x+1]<j) r++;   // if any larger val that is greater than x is present in affected area then round will increase
        if(pos[x-1]>i and pos[x-1]<j) r--;   // if any smaller val that is smaller than x is present in affected area then round will decrease
        if(pos[y+1]>i and pos[y+1]<j) r--;   // if any larger val that is larger than y is present in affected area then round will decrease, larger val will stay there & smaller val will go to first
        if(pos[y-1]>i and pos[y-1]<j) r++;   // if any smaller val that is smaller than y is present in affected area then round will increase, smaller val will stay there & larger val will go to first

        // case when consecutive ele
        if(x==y+1) r--;
        if(x==y-1) r++;

        cout<<r<<nl;

        // perform the operation
        swap(v[i], v[j]);
        pos[x] = j;
        pos[y] = i;
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
Here 1 to n permutation is given, Task is collect the nums from 1 to n in increasing order from the given array's order.
But here also there is m queries, with given two indices, swap the index's val and check how many round are needed.

Example: n = 5, m = 3, [4,2,1,5,3] with queries:
    swap 2,3: [4,1,2,5,3]
        In R1: takes 1,2,3
           R2: takes 4,5. So total 2 rounds.

    Swap 1,5: [3,1,2,5,4]
        In R1: takes 1,2
           R2: takes 3,4
           R3: takes 5, total 3 rounds.

    Swap 2,3: [3,2,1,5,4]
        In R1: 1
           R2: 2
           R3: 3,4
           R4: 5, total 4 rounds needed.

Observations:
1. There is atleast Round 1.
2. If x comes before x-1 then a new round starts. So, pos[x] < pos[x-1], cnt++.

At first, I need to count the total round first, then I will check the round needed by their queries.

Let, swap the eles of positions i,j and their val is x,y:
    Means, pos[i] = x and pos[j] = y.

    pos = [...i....j...],  [i+1, j-1] is the affected portion
    val = [...x....y...]

    Let, the middle ele of [x,y] is less than y (<y) and y needed to swap with x, then the round will be increase (r++).
    Because the y comes first and any val less than y comes next, then new round starts.

    Now think that, the middle ele of [x,y] is greater than y (>y) and y also needed to swap with x, then the round will decrease (r--).
    Because the y comes first and any val greater than y comes next, then we will able to take the both in a single round.

    Now, the same for the index i:
    The middle ele of [x,y] or the ele of the affected portion is less than x (x>) and x needed to swap with y, then round will be reduce (r--).
    Because the larger val x will go to the last of the portion and the smaller val will stay its position, then we can take both in a single round.

    The middle ele of [x,y] or the ele of the affected portion is greater than x (x<) and x needed to swap with y, then round will be increase (r++).
    Because the ele of affected area will stay there and its larger than x & x will move to the last of affected area then there another round will needed.

And also check the case that x & y are consecutive or not. 
    If x=1 & y=2 then it will be 2,1 and round will be r++.
    If x=2 & y=1 then it will be 1,2 and round will be r--.

So, The round's increment & decrement depends on the affected area. (pos[x+1]> i to pos[x+1]< j).

TC: O(n+m)
SC: O(n)
*/
