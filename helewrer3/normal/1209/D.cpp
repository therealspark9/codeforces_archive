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
vll a[nax], vis(nax, 0);
ll nds = 0;
set<pll> s;

void dfs(ll v, ll p){
	nds++;
	vis[v]++;
	for(auto it:a[v]){
		if(it == p)continue;
		s.insert({min(it, v), max(it, v)});
		if(!vis[it])dfs(it, v);
	}
}

void solve(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		u += m, v += m;
		a[i].pb(u);
		a[i].pb(v);
		a[u].pb(i);
		a[v].pb(i);
	}
	ll ans = 0;
	for(ll i = 0; i < m; i++){
		if(!vis[i]){
			nds = 0;
			s.clear();
			dfs(i, -1);
			// cout << sz(s) << " ";
			ans += ((sz(s) - nds) + 1);
		}
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