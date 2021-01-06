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

ll const nax = 2 * 1e5 + 5;
vll a[nax], dis(nax, 0);
void bfs(ll v){
	dis[v] = 0;
	queue<ll> q;
	q.push(v);
	while(!q.empty()){
		ll t = q.front();
		q.pop();
		for(auto it:a[t]){
			if(dis[it] > dis[t]+1){
				dis[it] = dis[t]+1;
				q.push(it);
			}
		}
	}
}

void solve(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)a[i].clear();
	for(ll i = 1; i <= n; i++)dis[i] = inf;
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	bfs(1);
	vll r, b;
	for(ll i = 1; i <= n; i++){
		if(dis[i]%2)r.pb(i);
		else b.pb(i);
	}
	if(sz(r) < sz(b)){
		cout<<sz(r) << endl;
		for(auto it:r)cout<<it<<" ";
	}
	else{
		cout<<sz(b) << endl;
		for(auto it:b)cout<<it<<" ";
	}
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