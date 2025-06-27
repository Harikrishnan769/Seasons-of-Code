#include<iostream>
#include<map>
#include<vector>
typedef long long ll;
using namespace std;
int main() {
  ll n, sum ; 
  cin>>n>>sum;
  map< ll, ll >numbers;
  vector<ll> num(n, 0);
  for ( ll i = 0 ; i < n ; i++ ) {
    cin>>num[i];
  }
  for ( ll i = 0 ; i < n ; i++ ) {
    ll ans = sum - num[i];
    if ( numbers.count(ans)){
    cout<<numbers[ans]+1<<" "<<i+1;
    return 0;
    }
    numbers[num[i]] = i;
  }
  cout<<"IMPOSSIBLE";
  return 0;

}