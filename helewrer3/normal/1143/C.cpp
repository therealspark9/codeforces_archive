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

ll const nax = 1e5 + 5;
vll a[nax], color(nax, 0), ans;

void dfs(ll v, ll p){
	if(color[v]){
		bool f = false;
		for(auto it:a[v]){
			if(it == p)continue;
			if(!color[it])f = true;
		}
		if(!f)ans.pb(v);
	}
	for(auto it:a[v]){
		if(it == p)continue;
		dfs(it, v);
	}
}


void solve(){
	ll n, r;
	cin >> n;
	r=1;
	for(ll i = 1; i <= n; i++){
		ll v, c;
		cin >> v >> c;
		color[i] = c;
		if(v!=-1){
			a[i].pb(v);
			a[v].pb(i);
		}
		else r = i;
	}
	dfs(r, 0);
	if(sz(ans)){
		sort(all(ans));
		for(auto it:ans)cout<<it<<" ";
	}
	else cout << -1;
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