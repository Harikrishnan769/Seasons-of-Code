#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;
int main() {
    ll n , m;
    cin>>n>>m;
    vector<vector<ll>> adj (n + 1);
    for ( ll i = 0 ; i < m ; i++ ) {
        ll a , b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<ll> colour ( n + 1 , 0 );
    queue <ll> q;
    for ( ll i = 1 ; i <= n ; i++ ) {
        if ( colour[i] != 0 ) 
        continue;
        colour[i] = 1;
        q.push(i);
    while ( !q.empty()) {
        ll v = q.front();
        q.pop();
        for ( auto x : adj[v]) {
            if ( colour[x] == 0 ) {
                colour[x] = 3 - colour[v];
            }
            else if ( colour[x] == colour[v]) {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
            else continue;
            q.push(x);
        }
    }
}
    for ( ll i = 1 ; i <= n ; i++ ) {
        cout<<colour[i]<<" "<<flush;
    }
}
