#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int main() {
      string s;
      cin>>s;
      int count = 1 , maximum = 1;
      for ( int i = 0 ; i < s.length() - 1 ; i++ ) {
             if ( s[i] == s[i+1] ) {
             count++;
             maximum = max(count, maximum);
             }
             else 
             count = 1;       
      }
      cout<<maximum;
      }      


