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

ll const nax = 1e6+5;
char a[1001][1001];
map<pll, ll> vis;
vll ans(nax,0);
ll dx[4] = {0,1,-1,0};
ll dy[4] = {1,0,0,-1};
ll n, m;


void dfs(ll i, ll j, ll t){
	vis[{i,j}] = t;
	for(ll k = 0; k < 4; k++){
		if(i+dx[k] < 0 or i+dx[k] >= n or j+dy[k] < 0 or j+dy[k] >= m)continue;
		ll x = i+dx[k], y = j+dy[k];
		if(a[x][y] == '.' and !vis.count({x,y}))dfs(x,y,t);
		else if(a[x][y] == '*')ans[t]++;
	}
}

void solve(){
	ll k;
	cin >> n >> m >> k;
	for(ll i = 0; i < nax; i++)ans[i] = 0;
	ll t = 1;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin>>a[i][j];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++){
		if(a[i][j] == '.' and !vis.count({i,j})){
			dfs(i,j,t);
			t++;
		}
	}
	while(k--){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		cout << ans[vis[{u,v}]] << endl;
	}
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