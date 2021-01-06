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

ll const nax = 2 * 1e5+5;
vll a[nax], b(nax, 0), c(nax, 0), d(nax, 0);

ll dfs_ch(ll v, ll p){
	ll mx = 0;
	for(auto it:a[v]){
		if(it == p)continue;
		mx += max(0ll, dfs_ch(it, v));
	}
	if(b[v] == 1)mx++;
	else mx--;
	c[v] = mx;
	return mx;
}

void dfs_ans(ll v, ll p, ll ans){
	d[v] = max(c[v], ans+c[v]);	
	for(auto it:a[v]){
		if(it == p)continue;
		dfs_ans(it, v, d[v]-max(0ll, c[it]));
	}
}

void solve(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++)cin>>b[i];
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	d[1] = dfs_ch(1, 0);
	dfs_ans(1, 0, d[1] - max(0ll, c[1]));
	
	for(ll i = 1; i <= n; i++)cout<<d[i]<<" ";
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