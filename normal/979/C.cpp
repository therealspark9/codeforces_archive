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

ll const nax = 3 * 1e5 + 5;
vll a[nax], vis(nax, 0);
ll z = 0;

void dfs(ll v, ll y, bool f){
	vis[v] = 1;
	if(f)z++;
	if(v == y)f = 1;
	for(auto it:a[v]){
		if(vis[it])continue;
		// cout << v << " ";
		dfs(it, y, f);
	}
}

void solve(){
	ll n, x, y;
	cin >> n >> x >> y;
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	ll ans = n*(n-1);
	dfs(x, y, 0);
	ll p = z;
	z = 0;
	for(auto &it:vis)it = 0;
	dfs(y, x, 0);
	ll q = z;
	ans = ans - p - p*q - 1 - q;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi