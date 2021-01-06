//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n;
const ll nax = 10e5 + 5;
vll a[nax], b(nax), c(nax), d(nax, 0), ans;
ll res;

void dfs(ll v, ll p, ll pp){
	ll D = ((pp <= 0)? 0 : d[pp]);
	if(D%2 and b[v] == c[v]){
		ans.pb(v); 
		d[v] = D + 1;
		res++;
	}
	else if(D%2 == 0 and b[v] != c[v]){
		ans.pb(v);
		d[v] = D + 1;
		res++;
	}
	else d[v] = D;
	for(auto it:a[v]){
		if(it == p) continue;
		dfs(it, v, p);
	}
}

void input(){
	cin >> n;
}

void solve(){
	for(ll i = 1; i < n; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	
	for(ll i = 1; i <= n; i++)cin >> b[i];
	for(ll i = 1; i <= n; i++)cin >> c[i];
	
	dfs(1, 0, -1);
	
	cout << res << endl;
	for(auto it:ans)cout << it << endl;
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
        cout<<endl;
	}
	cin.get();
	return 0;
}