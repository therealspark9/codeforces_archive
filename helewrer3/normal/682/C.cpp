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

ll const nax = 1e5+5;
ll ans = 0;
vector<pll> a[nax];
vll b(nax), dp(nax, 0);

void dfs(ll v, ll p, bool f, ll c){
	dp[v] = max(dp[p]+c, c);
	if(dp[v] > b[v])f = true;
	if(f)ans++;
	for(auto it:a[v])if(it.f != p)dfs(it.f, v, f, it.s);
}

void solve(){
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++)cin >> b[i];
	for(ll i = 2; i <= n; i++){
		ll v, c;
		cin >> v >> c;
		a[i].pb({v, c});
		a[v].pb({i, c});
	}
	dfs(1,0,0,0);
	cout<<ans;
	
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