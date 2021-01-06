//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, k;
ll const nax = 2 * 1e5 + 5;
vll a[nax], dis(nax, 0), sub(nax, 0), inc(nax, 0);

ll dfs(ll v, ll p){
	dis[v] = dis[p]+1;
	sub[v] = 1;
	for(auto it:a[v]){
		if(it == p)continue;
		sub[v] += dfs(it, v);
	}
	inc[v] = (sub[v] - 1) - (dis[v] - 1);
	return sub[v];
}

void input(){
	cin >> n >> k;
}

void solve(){
	inc.resize(n+1);
	for(ll i = 0; i < n-1; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	ll ans = 0;
	dfs(1, 0);
	inc[0] = -inf;
	sort(rall(inc));
	for(ll i = 0; i < n-k; i++)ans+=inc[i];
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}