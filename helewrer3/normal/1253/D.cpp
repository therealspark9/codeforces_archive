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
vll a[nax];
vll vis(nax, 0);
ll mn = inf, mx = -inf, nmn = inf, nmx = -inf;

void dfs(ll v, ll p){
	vis[v]++;
	nmn = min(nmn, v);
	nmx = max(nmx, v);
	for(auto it:a[v]){
		if(it == p)continue;
		if(!vis[it]) dfs(it, v);
	}
}

void solve(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >>u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			nmn = inf, nmx = -inf;
			dfs(i, 0);
			if(mx < nmn or mn > nmx) mn = nmn, mx = nmx;
			else{
				ans++;
				mx = max(mx, nmx);
				mn = min(mn, nmn);
			}
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