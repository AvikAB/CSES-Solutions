// Play the game here: https://www.mathsisfun.com/games/towerofhanoi.html

// Tower of Hanoi

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

void tower(ll n, ll start, ll end, ll middle){
    // base case
    if(n==1){
        cout<<start<<" "<<end<<nl;
        return;
    }

    // s-1: moves n-1 disks from start to middle using end
    tower(n-1, start, middle, end);   // call 1

    cout<<start<<" "<<end<<nl;   // s-2: move largest disk to the end

    //s-3: that n-1 disks from middle will go to end using start
    tower(n-1, middle, end, start);  // call 2
}

void solve(){
    ll n;
    cin>>n;
    cout<<(1<<n)-1<<nl;
    tower(n, 1, 3, 2);   // (disks, start(1), end(3), helper/middle(2))
}

int main(){
    FASTER
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}









/*
There are total 2 rules:
1. Move only 1 disc at a time.
2. You can't place a larger disc on a smaller disc.

There is total 3 towers, Left(start), Middle(helper), Right(end). This problem can be solved using recursion.
Here the calling function is tower(num_of_disks, start_pos, end_pos, helper_pos).

See the patterns:
*n=1, then directly start to end.

*n=2, then 1st disk to middle, last disk to end and then 1st disk middle to end. Total 3 moves.

*n=3, From start tower, the first 2 disks will go to the middle tower from start using the end.
        For this the recursive call will be: tower(2, s, m, e) -> 3 moves.

        Then 3rd disk will move from start to end. Just print s & e -> 1 moves.

        Then that 2 disks from middle will go to the end using start as their helper tower.
        For this the recursive call is: tower(2, m, e, s) -> 3 moves.
    For 3, total moves is 7.

*n=4, First 3 disks move to the middle from start using end tower. recursive call: tower(3, s, m, e) -> 7 moves.

      Now the only one disk from start will go to the end tower directly. Just print s & e, -> 1 moves.

      Now the 3 disks from the middle will go to the end tower using start tower. recursive call: tower(3, m, e, s) -> 7 moves.
    For 4, total moves is 15.

So, the pattern is:
Step-1: Move 'n-1' disks from "start" to "middle" using "end" as their helper tower.
        call: tower(n-1, s, m, e).

Step-2: Move largest disk directly to the "end" tower from "start".
        print: s, e.

Step-3: That 'n-1' disks from the "middle" move to the "end" using "start" tower as their helper tower.
        call: tower(n-1, m, e, s).

Here, the base case is if (n==1) then the move is from "start" to "end".

And the total moves are: (2^n)-1.

Time Comp: O(2^n).
Space Comp: O(n).


Dry run the code for n=2:

Initial call:
    solve()
    Read: n=2
    Print moves count: (2×2)−1=3
    Call: tower(2, s=1, e=3, m/h=2)

Call 1: tower(2, 1, 3, 2)
    n!=1, so:
    Call: tower(1, s=1, m=2, e=3)

Call 2: tower(1, 1, 2, 3)
    n==1: print start end → 1 2
    Return to Call 1.

Back to Call 1:
    After recursive call, print start end → 1 3
    Then call: tower(1, m=2, e=3, s=1)

Call 3: tower(1, 2, 3, 1)
    n==1: print start end → 2 3
    Return to Call 1.

Back to Call 1:
Function ends.
*/
