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

const ll nax = 5ll*1e3+5;
vector<pll> a[nax];
vll dp[nax];

vll dfs(ll v, ll p, ll t, ll k, ll n){
	vll ans;
	if(t > k)return ans;
	if(v == n){
		ans.pb(n);
		return ans;
	}
	if(sz(dp[v]))return dp[v];
	for(auto it:a[v]){
		if(it.f == p)continue;
		vll tans = dfs(it.f, v, t+it.s, k, n);
		if(sz(tans) > sz(ans) and tans[0] == n) ans = tans;
	}
	ans.pb(v);
	return dp[v] = ans;
}

void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	for(ll i = 0; i < m; i++){
		ll u, v, c;
		cin >> u >> v >> c;
		a[u].pb({v,c});
	}
	vll v = dfs(1,0,0,k,n);
	cout << sz(v) << endl;
	reverse(all(v));
	for(auto it:v)cout<<it<<" ";
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