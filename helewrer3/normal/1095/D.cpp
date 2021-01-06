//May the force be with me
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
vector<pll> a;
vll ans, vis;

void bc(ll v){
	if(vis[v])return;
	ans.pb(v);
	ll x = a[v].f, y = a[v].s;
	if(a[y].f == x or a[y].s == x) swap(x, y);
	if(vis[x])return;
	ans.pb(x);
	vis[x] = vis[v] = 1;
	bc(y);
}

void solve(){
	ll n;
	cin >> n;
	a.resize(n+1);
	vis.resize(n+1);
	for(ll i = 1; i <= n; i++)cin >> a[i].f >> a[i].s;
	for(ll i = 1; i <= n; i++)vis[i] = 0;
	bc(1);
	for(ll i = 0; i < sz(ans); i++)cout<<ans[i]<<" ";
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