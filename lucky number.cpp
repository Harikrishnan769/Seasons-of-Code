#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
int diff ( int n ) {
    int maxdig = n % 10, mindig = n % 10;
    while ( n > 0 ) {
           maxdig = max ( maxdig, n % 10);
           mindig = min ( mindig, n % 10);
           n /= 10;
    }
    return maxdig - mindig;
}
int main() {
    ll testcases;
    cin>>testcases;
    while ( testcases-- ) {
        ll l,r;
        cin>>l>>r;
        ll luckiest = l;
        int maxdif = diff(l);
        for ( ll i = l+1 ; i <= min ( r,l+100 ) ; i++ ) {
            int d = diff(i);
            if ( d > maxdif ) {
                luckiest = i;
                maxdif = d;
            }
            if ( maxdif == 9 ) break;
        }
        cout<<luckiest<<endl;
    }

}