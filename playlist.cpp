#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
typedef long long ll;
int main() {
  ll n;
  cin>>n;
  vector<ll> songs ( n , 0);
  unordered_set<ll> seq;
  ll max_length = 0, j = 0;
  for ( ll i = 0 ; i < n ; i++ ) {
    cin>>songs[i];
  }
  for ( ll i = 0 ; i < n ; i++ ) {
    while ( seq.count(songs[i])) {
        seq.erase(songs[j]);
            j++;
    }
    seq.insert(songs[i]);
    max_length = max(max_length, i-j+1);
  }
  cout<<max_length;

}