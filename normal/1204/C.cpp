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
using namespace std;

ll const nax = 101;
vll a[nax], dis[nax];

void bfs(ll v){
	dis[v].resize(nax);
	for(auto &it:dis[v]) it = inf;
	dis[v][v] = 0;
	queue<ll> q;
	q.push(v);
	while(!q.empty()){
		ll top = q.front();
		q.pop();
		for(auto it:a[top]){
			if(dis[v][it] > dis[v][top] + 1){
				dis[v][it] = dis[v][top] + 1;
				q.push(it);
			}
		}
	}
}

void solve(){
	ll n, m;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		string s;
		cin >> s;
		for(ll j = 0; j < sz(s); j++) if(s[j] == '1')a[i].pb(j+1);
	}
	cin >> m;
	vll b(m);
	for(auto &it:b)cin>>it;
	for(ll i = 1; i <= n; i++)bfs(i);
	vll ans;
	ans.pb(b[0]);
	ll prev = b[0];
	for(ll i = 1; i < m-1; i++){
		if(dis[b[i]][b[i+1]] + dis[prev][b[i]] > dis[prev][b[i+1]]){
			prev = b[i];
			ans.pb(b[i]);
		}
	}
	ans.pb(b[m-1]);
	cout << sz(ans) << endl;
	for(auto it:ans)cout << it << " ";
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