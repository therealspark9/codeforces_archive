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

ll const nax = 1e5 + 5;
vll a[nax], vis(nax, 0);
ll ans = 0;
map<pll, ll> mp;

void dfs(ll v, ll p){
	if(vis[v])return;
	vis[v] = 1;
	for(auto it:a[v]){
		if(it == p)continue;
		if(!mp.count({min(it,v), max(it,v)}) and max(it, v) <= 6){
			ans++;
			mp[{min(it,v), max(it,v)}] = 1;
		}
		dfs(it, v);
	}
}

void solve(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	for(ll i = 1; i <= n; i++) if(!vis[i]) dfs(i,0);
	if(n > 6){
		ll tans = 0;
		vll c(7, 0);
		for(auto it:a[7])c[it]++;
		for(ll i = 1; i <= 6; i++){
			if(!c[i]){
				ll ttans = sz(a[7]);
				vll b(10, 0);
				for(auto it:a[i]) for(ll j = 1; j <= 6; j++) if(!mp.count({min(it, j), max(it, j)}))b[j]++;
				ll x = 0;
				for(auto it:b)x = max(x, it);
				ll y = sz(a[i]);
				tans = max(tans, ttans + x - y);
			}
			else{
				ll x = 0;
				for(auto it:a[7]) if(!mp.count({min(it, i), max(it, i)}))x++;
				tans = max(tans, x);
			}
		}
		ans += tans;
	}
	cout<<ans;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi