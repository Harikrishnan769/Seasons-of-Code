#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<ll> duration(n,0);
    vector<ll> deadline(n,0);
    for ( int i = 0 ; i < n ; i++ ) {
        cin>>duration[i]>>deadline[i];
    }
    sort(duration.begin(), duration.end()); 

    ll current_time = 0;
    ll total_reward = 0;

    for (int i = 0; i < n; i++) {
        current_time += duration[i];
        total_reward += deadline[i] - current_time; 
    }

    cout << total_reward << "\n";
}
