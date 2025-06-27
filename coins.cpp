#include<iostream>
using namespace std;
typedef long long ll;
int main() {
    ll no_of_test;
    cin>>no_of_test;
    for ( ll i = 0 ; i < no_of_test ; i++ ) {
        ll n , k;
        cin>>n>>k; 
        if ( n % 2 == 0 ) {
            cout<<"YES"<<endl;
        }
        else {
            if ( k % 2 == 0 ) {
                cout<<"NO"<<endl;
            }
            else {
                if ( n < k )
                cout<<"NO"<<endl;
                else
                cout<<"YES"<<endl;
            }
        }
        }
    }