#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
    ll n ;
    cin>>n;
    ll cost = 0;
  vector<ll> numbers(n,0);
  for ( ll i = 0 ; i < n ; i++ ) {
              cin>> numbers[i];
  }
  sort(numbers.begin() , numbers.end());
  ll median = numbers[n/2];
  for ( ll i = 0 ; i < n ; i++ ) {
    cost += abs(numbers[i] - median);
  }
  cout<<cost;
  }

