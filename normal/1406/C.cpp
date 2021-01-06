//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
const ll nax = 10e5 + 5;
ll n, mn, c1, c2, s;
vll sze(nax), p(nax), a[nax];

void dfs(ll v, ll prev){
	p[v] = prev, sze[v] = 1;
	ll mx = -inf;
	for(auto it:a[v]){
		if(prev == it) continue;
		dfs(it, v);
		sze[v] += sze[it];
		mx = max(mx, sze[it]);
	}
	mx = max(mx, n - sze[v]);
	if(mx < mn)mn = mx, c1 = v, c2 = 0;
	else if(mx == mn)c2 = v;
}

void dfs1(ll v, ll prev){
	if(sz(a[v]) == 1ll){
		s = v;
		return;
	}
	for(auto it:a[v]){
		if(it == prev) continue;
		dfs1(it, v);
	}
}

void input(){
	cin >> n;
	mn = 10e9, c1 = 0, c2 = 0;
	for(int i=1;i<=n;i++)a[i].clear(),p[i]=0;
}

void solve(){
	for(ll i = 0; i < n - 1; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v), a[v].pb(u);
	}
	dfs(1, 0);
	if(!c2){
		cout << "1 " << a[1][0] << endl << "1 " << a[1][0];
		return;
	}
	if(p[c1] != c2)swap(c1, c2);
	dfs1(c1, c2);
	cout << s << " " << p[s] << endl << s << " " << c2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}