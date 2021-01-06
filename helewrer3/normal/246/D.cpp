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
const ll nax = 10e5+1;

ll n, m;
vll c;
set<ll> s[nax];

void input(){
	cin >> n >> m;
	c.resize(n);
}


void solve(){
	for(ll i = 0; i < n; i++)cin >> c[i];
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		if(c[u] == c[v])continue;
		s[c[u]].insert(c[v]);
		s[c[v]].insert(c[u]);
	}
	ll ans = 0;
	for(ll i = 0; i < nax; i++) ans = max(ans, sz(s[i]));
	if(ans){for(ll i = 0; i < nax; i++)if(ans==sz(s[i])){cout<<i;return;}}
	else sort(all(c)),cout<<c[0];
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