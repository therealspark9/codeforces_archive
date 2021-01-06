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
vll a[nax], b(nax, 0);
ll tr, tb, ans;

pll dfs(ll v, ll p){
	pll c = {0,0};
	for(auto it:a[v]){
		if(it == p)continue;
		pll tc = dfs(it, v);
		c.f += tc.f, c.s += tc.s;
	}
	if(b[v] == 1)c.f++;
	else if(b[v] == 2)c.s++;
	if(c.f == tr and c.s == 0)ans++;
	else if(c.s == tb and c.f == 0)ans++;
	return c;
}

void solve(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++)cin >> b[i];
	for(ll i = 1; i <= n; i++){
		if(b[i] == 1)tr++;
		else if(b[i] == 2)tb++;
	}
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(1,0);
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