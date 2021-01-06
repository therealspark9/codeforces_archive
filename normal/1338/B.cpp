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
vll a[nax];
vll dis(nax, 0);
void bfs(ll v, ll n){
	for(ll i = 1; i <= n; i++)dis[i] = inf;
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
	ll n;
	cin >> n;
	for(ll i = 0; i < n-1; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	bfs(1, n);
	vll b;
	for(ll i = 1; i <= n; i++)if(sz(a[i]) == 1)b.pb(i);
	sort(rall(b));
	bool f = true;
	for(ll i = 1; i < sz(b); i++)f &= (dis[b[0]]%2 == dis[b[i]]%2);
	ll mn = 1, mx = n-1;
	if(!f)mn = 3;
	vll vis(n+1, 0);
	for(ll i = 0; i < sz(b); i++){
		if(!vis[a[b[i]][0]]){
			vis[a[b[i]][0]] = 1;
			ll len = 0;
			for(auto it:a[a[b[i]][0]]) if(sz(a[it]) == 1)len++;
			mx = mx - len + 1;
		}
	}
	cout << mn << " " << mx; 
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