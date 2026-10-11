// Main Josephus Problem & its logic:
// n, k given, every kth person will die (k-1).

// Recursive Way (O(n^2)):
void josephus(vector<ll>&v, ll k, ll idx){
    if(v.size()==1){    // base case
        cout<<v[0]<<nl;  // safe place
        return;
    }

    // find index of person to kill
    idx = (idx+k-1) % v.size();
    cout<<v[idx]<<" ";

    // remove the killed person
    v.erase(v.begin()+idx);

    josephus(v, k, idx);
}

void solve(){
    ll n,k;
    cin>>n>>k;
    vector<ll>v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    ll idx = 0;   // starting idx
    josephus(v, k, idx);
}

/*
TC: O(n^2), because of erase() function.
This problem define in recursively. Each and every round there will reduce n-1 people untill n = 1.

The game starts with 0th index, means with the 1st people. Here, people's order (1,2,...) will not change, just change their index.
And always the removed person will be idx = (idx+k-1) % size.

Base Case: if(size==1) return; or we got the safe place.

*/
