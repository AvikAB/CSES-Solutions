#include<iostream>
#include<set>
using namespace std;
int main(){
    int n;
    cin>>n;
    set<int>s;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
}

// Just take the alements on set and It will given the distinct of every eles.
