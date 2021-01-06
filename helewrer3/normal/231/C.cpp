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
  ll n, k;
  cin >> n >> k;
  vll a(n), b(n, 0), c(n, 0);
  for(auto &it:a)cin>>it;
  sort(all(a));
  for(ll i = n-2; i >= 0; i--)b[i] = b[i+1]+(a[i+1]-a[i]);
  for(ll i = n-2; i >= 0; i--)c[i] = b[i];
  for(ll i = n-2; i >= 0; i--)c[i] += c[i+1];
  ll ans = 0, val = inf;
  for(ll i = 0; i < n; i++){
    ll l = 0, r = i, midd = -1;
    while(l <= r){
      ll mid = (l+r)/2;
      if((c[mid]-c[i])-(i-mid)*b[i] <= k)midd = mid, r = mid - 1;
      else l = mid + 1;
    }
    if(midd != -1){
      if(ans < i-midd+1) ans = i-midd+1, val = a[i];
      else if(ans == i-midd+1) val = min(val, a[i]);
    }
  }
  cout << ans << " " << val;
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