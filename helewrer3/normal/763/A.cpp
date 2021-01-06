//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

const ll nax = 1e5+5;
ll n;
bool f;
vll a[nax], vis(nax, 0), c;

void input(){
	cin >> n;
}

void dfs(ll v,ll color, ll p){
	if(color != c[v])f = false;
	for(auto it:a[v])if(it != p)dfs(it, color, v);
}

void solve(){
	for(ll i = 0; i < n-1; i++){
		ll u, v;
		cin >> u >> v;
		u--, v--;
		a[u].pb(v);
		a[v].pb(u);
	}
	vll r;
	c.resize(n);
	for(auto &it:c)cin >> it;
	for(ll i = 0; i < n; i++){
		f = false;
		for(ll j = 0; j < sz(a[i]); j++)
			if(c[i] != c[a[i][j]]){
				r.resize(2);
				r[0] = i, r[1] = a[i][j];
			}
	}
	if(!sz(r))cout << "YES\n1";
	else{
		for(ll i = 0; i < min(100ll, sz(r)); i++){
			ll it = r[i];
			f  = true;
			for(auto jt:a[it])dfs(jt, c[jt], it);
			if(f){
				cout<<"YES\n"<<it+1;
				return;
			}	
		}
		cout << "NO";
	}
			
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}