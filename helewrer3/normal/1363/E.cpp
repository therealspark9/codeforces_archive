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
vll a[nax];
vector<pair<ll, pll>> b(nax);
ll ans = 0;

void pdfs(ll v, ll p){
	b[v].f = min(b[v].f, b[p].f);
	for(auto it:a[v]){
		if(it == p)continue;
		pdfs(it, v);
	}
}

pll dfs(ll v, ll p){
	pll c = {0,0};
	for(auto it:a[v]){
		if(it == p)continue;
		pll tc = dfs(it, v);
		c.f += tc.f, c.s += tc.s;
	}
	if(b[v].s.f == 1 and b[v].s.s == 0)c.f++;
	else if(b[v].s.f == 0 and b[v].s.s == 1)c.s++;
	ll d = min(c.f, c.s);
	ans += 2*d*b[v].f;
	c.f -= d, c.s -= d;
	return c;
}

void solve(){
	ll n;
	cin >> n;
	b[0] = {inf, {0,0}};
	for(ll i = 1; i <= n; i++)cin >> b[i].f >> b[i].s.f >> b[i].s.s;
	ll o = 0, z = 0;
	for(ll i = 1; i <= n; i++){
		if(b[i].s.f == 0 and b[i].s.s == 1)o++;
		else if(b[i].s.f == 1 and b[i].s.s == 0)z++;
	}
	if(o != z){
		cout <<	-1;
		return;
	}
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	pdfs(1,0);
	dfs(1, 0);
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