#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long int min = 0;
    vector<long long int> A ( n, 0 );
    for ( int i = 0 ; i < n ; i++ ) {
        cin>>A[i];
        if ( i == 0 ){
        continue;
        }
        if ( A[i] < A[i - 1]) {
            min += A[i - 1] - A[i];
            A[i] += A[i - 1] - A[i];
            
        }
    }
    cout<<min;
}