//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
#define endl "\n"
using namespace std;


void solve(){
  ll r1, r2;
  cin >> r1 >> r2;
  for(ll i = -r1; i <= r1; i++){
    if(!i)continue;
    ll y = r1*r1 - i*i, x = i;
    if(ceil(sqrt(y)) != floor(sqrt(y))) continue;
    y = sqrt(y);
    if((x*x*r2*r2)%(r1*r1))continue;
    ll y_alt = (x*x*r2*r2)/(r1*r1);
    if(ceil(sqrt(y_alt)) != floor(sqrt(y_alt))) continue;
    y_alt = sqrt(y_alt);
    if((y*y_alt)%x)continue;
    ll x_alt = -(y*y_alt)/x;
    if(min(abs(x), abs(y)) == 0 or min(abs(x_alt), abs(y_alt)) == 0) continue;
    if(x == x_alt or y == y_alt)continue;
    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << x << " " << y << endl;
    cout << x_alt << " " << y_alt << endl;
    return;
  }
  cout<<"NO";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  ll t = 1;
  //cin >> t;
  while(t--){
    solve();
    cout << endl;
  }
  return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi