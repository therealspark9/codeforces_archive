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
using namespace std;

ll const nax = 5 * 1e5 + 5;
vll a[nax], b(nax), vis(nax), ans;

void dfs(ll v){
	ll mx = 0;
	for(auto it:a[v]){
		if(b[it] < b[v] and !vis[it])dfs(it);
		else if(b[it] == b[v]){
			cout << -1;
			exit(0);
		}
		mx = max(mx, b[it]);
	}
	mx = max(mx, b[v]);
	vector<bool> f(mx+1,0);
	for(auto it:a[v])f[b[it]] = 1;
	for(ll i = 1; i <= mx; i++){
		if(!f[i]){
			if(i == b[v]) break;
			else{
				cout << -1;
				exit(0);
			}
		}
	}
	ans.pb(v);
	vis[v] = 1;
}

bool mc(ll x, ll y){return b[x] < b[y];}

void solve(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	for(ll i = 1; i <= n; i++) cin >> b[i];
	for(ll i = 1; i <= n; i++) if(!vis[i])dfs(i);
	for(auto it:ans)cout << it << " ";
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