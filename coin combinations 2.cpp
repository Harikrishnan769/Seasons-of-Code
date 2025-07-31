#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    ll n, x;
    cin >> n >> x;
    const ll MOD = 1e9 + 7;

    vector<ll> coins(n);
    for (ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;  
    for (ll i = 0; i < n; i++) {
        for (ll j = coins[i]; j <= x; j++) {
            dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
        }
    }

    cout << dp[x] << "\n";
}
