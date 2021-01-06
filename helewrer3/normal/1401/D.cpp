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

ll const nax = 2 * 1e5 + 5;
vll edg, a[nax];
ll n;

ll dfs(ll v, ll p){
	ll dwn = 1;
	for(auto it:a[v]){
		if(it == p) continue;
		dwn = (dwn+dfs(it, v));
	}
	if(p)edg.pb((dwn*(n-dwn)));
	return dwn;
}

void solve(){
	cin >> n;
	for(ll i = 1; i <= n; i++)a[i].clear();
	edg.clear();
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(1,0);
	ll k;
	cin >> k;
	vll p(k);
	for(auto &it:p)cin>>it;
	sort(all(edg));
	sort(all(p));
	bool f = false;
	while(sz(p) < sz(edg)) p.pb(1), f = true;
	if(f)sort(all(p));
	while(sz(p) > sz(edg)){
		ll u = p.back();
		p.pop_back();
		ll v = p.back();
		p.pop_back();
		ll x;
		x = (u*v)%mod;
		p.pb(x);
	}
	ll ans = 0;
	for(ll i = 0; i < sz(edg); i++)ans=(ans+(edg[i]*(p[i]%mod))%mod)%mod;
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi