//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n;
const ll nax = 1e6;
vll a[nax], c(nax, 0), vis(nax, 0);

void input(){
	cin >> n;
}

void dfs(ll v, ll p){
	if(vis[v])return;
	vis[v] = 1;
	ll t = 0;
	for(auto it:a[v]){
		if(vis[it])continue;
		t++;
		if(t == c[v] or t == p)t++;
		if(t == c[v] or t == p)t++;
		c[it] = t;
		dfs(it, c[v]);
	}
}

void solve(){
	for(ll i = 0; i < n-1; i++){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		a[u].pb(v);
		a[v].pb(u);
	}
	c[0] = 1;
	dfs(0,-1);
	mll mp;
	for(ll i = 0; i < n; i++)mp[c[i]]++;
	cout<<mp.size()<<endl;
	for(ll i = 0; i < n; i++)cout<<c[i]<<" ";
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}