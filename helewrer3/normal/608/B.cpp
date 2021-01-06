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
	string a, b;
	cin >> a >> b;
	pll p = {0,0};
	ll r = sz(b);
	vector<pll> c(sz(b));
	if(b[sz(b)-1] == '1')c[sz(c)-1] = {1,0};
	else c[sz(c)-1] = {0,1};
	for(ll i = sz(c)-2; i >= 0; i--){
		c[i] = c[i+1];
		if(b[i] == '1')c[i].f++;
		else c[i].s++;
	}
	ll ans = 0;
	for(ll i = sz(a)-1; i >= 0; i--){
		pll tp = c[i];
		tp.f -= p.f;
		tp.s -= p.s;
		if(a[i] == '1')ans += tp.s;
		else ans += tp.f;
		r--;
		p = c[r];
	}
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