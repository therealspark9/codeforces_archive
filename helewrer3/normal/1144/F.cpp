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

const ll nax = 2 * 1e5 + 5;
vll a[nax], color(nax), vis(nax, 0), c(nax, 0);
vector<pll> b(nax);

void dfs(ll v, ll p){
	vis[v] = 1;
	for(auto it:a[v]){
		if(it == p)continue;
		if(!vis[it]){
			color[it] = 1 - color[v];
			dfs(it, v);
		}
		else if(color[it] == color[v]){
			cout<<"NO";
			exit(0);
		}
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
		b[i] = {u, v};
	}
	for(ll i = 1; i <= n; i++)color[i] = -1;
	color[1] = 0;
	dfs(1,0);
	cout<<"YES"<<endl;
	for(ll i = 0; i < m; i++) cout << color[b[i].s];
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