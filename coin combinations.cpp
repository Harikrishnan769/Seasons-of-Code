#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
     ll n, x;
     cin>>n>>x;
     vector<ll> coins(n,0);
    const ll MOD = 1e9+7;
     for ( int i = 0 ; i < n ; i++ ) {
        cin>>coins[i];
     }
     vector<ll> dp(x+1,0);
     dp[0] = 1;
     for ( int j = 0 ; j <= x ; j++ ) {
        for ( int k = 0 ; k < n ; k++ ) {
            dp[j] = (dp[j] + (j >= coins[k] ? dp[j-coins[k]] : 0))%MOD;
        }
     } 
       cout<<dp[x]; 
     }
