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

ll const nax = 2 * 1e3 + 5;
vll a[nax], b(nax, 0), c(nax, 0);

vector<pll> dfs(ll v, ll p){
	vector<pll> ans;
	for(auto it:a[v]){
		if(it == p)continue;
		vector<pll> tans = dfs(it, v);
		for(auto jt:tans)ans.pb(jt);
	}
	if(b[v] > sz(ans)){
		cout<<"NO";
		exit(0);
	}
	if(ans.empty())ans.pb({1e8, v});
	else{
		sort(all(ans));
		for(ll i = 0; i < b[v]; i++)ans[i].f-=10;
		if(b[v] != sz(ans)) ans.pb({ans[b[v]].f-1, v});
		else ans.pb({ans[b[v]-1].f+1, v});
	}
	return ans;
}

void solve(){
	ll n, r;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		ll u, d;
		cin >> u >> d;
		if(!u)r=i;
		else{
			a[u].pb(i);
			a[i].pb(u);
		}
		b[i] = d;
	}
	vector<pll> ans = dfs(r,0);
	for(auto it:ans)c[it.s] = it.f;
	cout<<"YES\n";
	for(ll i = 1; i <= n; i++)	cout << c[i]+1e3 << " ";
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