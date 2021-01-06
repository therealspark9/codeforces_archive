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
  ll n;
  cin >> n;
  vector<pll> a(n);
  for(auto &it:a)cin >> it.f >> it.s;
  sort(all(a));
  for(ll i = 1; i < n; i++){
    ll x = log2(a[i-1].s)/2;
    if(a[i].f-a[i-1].f<=x){
      ll y = pow(4, a[i].f-a[i-1].f);
      a[i].s = max(a[i].s, (a[i-1].s+(y-1))/y);
    }
  }
  ll x = log2(a[n-1].s)/2;
  if(1ll*pow(4,x) == a[n-1].s and x)cout << x+a[n-1].f;
  else cout <<x+a[n-1].f+1;
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