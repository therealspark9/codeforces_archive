/*May the force be with me*/
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

ll n, k, ans;
ll const nax = 2 * 10e5 + 5;
vll a[nax], b(nax, 0);

void dfs(ll v, ll c, ll t, ll p){
	if(b[v])c++;
	else c = 0;
	t = max(c, t);
	if(sz(a[v]) == 1 and v != 1){
		if(t <= k)ans++;
		return;
	}
	for(auto it:a[v]){
		if(it == p)continue;
		dfs(it, c, t, v);
	}
}

void input(){
	cin >> n >> k;
}

void solve(){
	for(ll i = 1; i <= n; i++)cin >> b[i];
	for(ll i = 0; i < n-1; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	dfs(1, 0, 0, 0);
	cout << ans;
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