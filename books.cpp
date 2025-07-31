#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    ll n, max_sum;
    cin>>n>>max_sum;
    vector<ll> cost(n,0);
    vector<ll> pages(n,0);
    for ( int i = 0 ; i < n ; i++ ) {
        cin>>cost[i];
    }
    for ( int i = 0 ; i < n ; i++ ) {
        cin>>pages[i];
    }
    vector<ll> dp(max_sum + 1,0);
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = max_sum ; j >= cost[i] ; j-- ) {
            dp[j] = max(dp[j-cost[i]] + pages[i], dp[j]);
        }
         
        }
        cout<<dp[max_sum];

    }

