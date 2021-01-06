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

ll const nax = 1e5+5;
vll a[nax];
vll vis(nax, 0);
void dfs(ll v, ll p){
	vis[v] = vis[p]+1;
	for(auto it:a[v]){
		if(it == p)continue;
		dfs(it, v);
	}
}

void solve(){
	ll n, sa, sb, da, db;
	cin >> n >> sa >> sb >> da >> db;
	for(ll i = 0; i <= n; i++)vis[i] = 0;
	for(ll i = 1; i <= n; i++)a[i].clear();
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	vis[0] = -1;
	dfs(sa, 0);
	ll mx = 0, dis = vis[sb];
	for(ll i = 1; i <= n; i++)mx = max(mx, vis[i]);
	for(ll i = 1; i <= n; i++)if(vis[i]==mx){
		for(ll j = 0; j <= n; j++)vis[j] = 0;
		// for(auto &it:vis)it = 0;
		vis[0] = -1;
		dfs(i,0);
		break;
	}
	mx = 0;
	for(ll i = 1; i <= n; i++)mx = max(mx, vis[i]);
	if(dis <= da)cout<<"Alice";
	else if(mx <= 2*da)cout<<"Alice";
	else if(db <= 2*da)cout<<"Alice";
	else cout<<"Bob";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi