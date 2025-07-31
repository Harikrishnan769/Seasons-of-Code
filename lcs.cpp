#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
    ll n , m;
    cin>>n>>m;
    vector<ll> set1(n,0);
    vector<ll> set2(m,0);
    for ( int i = 0 ; i < n ; i++ ) {
                cin>>set1[i];
    }
    for ( int i = 0 ; i < m ; i++ ) {
                cin>>set2[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(m+1,0));
    for ( ll i = 1 ; i <= n ; i++ ) {
        for ( ll j = 1 ; j <= m ; j++ ) {
                 if ( set1[i-1] == set2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                 }
                 else { 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

                 }
        }
    }
    cout<<dp[n][m]<<endl;
    vector<ll> lcs;
    ll i = n , j = m;
    while ( i > 0 && j > 0 ) {
        if ( set1[i-1] == set2[j-1]) {
            lcs.push_back(set1[i-1]);
            i--;
            j--;
        }
        else if ( dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    for ( auto x : lcs ) {
        cout<<x<<endl;
    }
}