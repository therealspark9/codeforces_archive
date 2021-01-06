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
	string s;
	cin >> s;
	ll a[4] = {0};
	for(auto it:s){
		if(it == 'A')a[0]++;
		if(it == 'C')a[1]++;
		if(it == 'G')a[2]++;
		if(it == 'T')a[3]++;
	}
	ll mx = 0;
	for(auto it:a)mx = max(it, mx);
	ll cnt = 0;
	for(auto it:a)if(it == mx) cnt++;
	ll ans = 1;
	for(ll i = 0; i < n; i++) ans = (ans * cnt)%mod;
	cout << ans;
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