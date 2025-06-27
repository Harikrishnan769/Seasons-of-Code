#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
    ll n;
    cin>>n;
    vector<vector<ll>> dist ( n + 1, vector<ll>(n + 1,-1));
    queue<pair<ll, ll>> q;
    int dx[] = {-1,-1,-2,-2,1,1,2,2};
    int dy[] = {2,-2,-1,1,-2,2,1,-1};
    q.push({1,1});
    dist[1][1] = 0;
    while ( !q.empty() ) {
        auto front = q.front();
         ll x = front.first;
         ll y = front.second;
         q.pop();
        for ( int k = 0 ; k < 8 ; k++ ) {
            ll nx = x+dx[k] ;
            ll ny = y+dy[k];
            if ( nx >= 1 && ny >= 1 && nx <= n && ny <= n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                 q.push({nx,ny});
            }
           
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1;  j <= n ; j++ ) {
            cout<<dist[i][j]<<" ";
            
        }
        cout<<endl;
    }
    }





