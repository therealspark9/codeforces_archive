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
vll a[nax], b(nax, 0), c(nax, 0);

void dfs(ll v, ll p){
	b[v] = b[p]+1;
	c[b[v]]++;
	for(auto it:a[v]){
		if(it == p)continue;
		dfs(it, v);
	}
}

void solve(){
	ll n;
	cin >> n;
	for(ll i = 1; i < n; i++){
		ll u,v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	for(ll i = 1; i <= n; i++)sort(all(a[i]));
	b[0] = -1;
	dfs(1, 0);
	vll d(n);
	for(auto &it:d)cin >> it;
	stack<ll> s;
	ll prev = 0;
	for(ll i = n; i >= 0; i--)s.push(i);
	for(ll i = 0; i < n; i++){
		if(b[d[i]] != s.top()){
			cout << "No";
			return;
		}
		ll len = sz(a[d[i]]) - 1;
		for(ll j = i + c[b[d[i]]] + prev; j < i + c[b[d[i]]] + prev + len; j++){
			auto it = lower_bound(all(a[d[i]]), d[j]);
			if(it == a[d[i]].end() or (*it) != d[j]){
				cout << "No";
				return;
			}
		}
		prev += len;
		c[b[d[i]]]--;
		if(!c[b[d[i]]])s.pop(), prev = 0;
	}
	cout<<"Yes";
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