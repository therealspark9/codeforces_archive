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

ll n, m, k;

void input(){
	cin >> n >> m >> k;
}

void solve(){
	vll a(n+1, 0), c(m+2, 0), d(n+2, 0), ans(n+1, 0);
	vector<pair<pll, ll>> b(m+1);
	for(ll i = 1; i <= n; i++)cin >> a[i];
	for(ll i = 1; i <= m; i++)cin >> b[i].f.f >> b[i].f.s >> b[i].s;
	for(ll i = 1; i <= k; i++){
		ll u, v;
		cin >> u >> v;
		c[u]++, c[v+1]--;
	}
	ll t = 0;
	for(ll i = 1; i <= m; i++){
		t += c[i];
		d[b[i].f.f] += t*b[i].s, d[b[i].f.s+1] -= t*b[i].s;
	}
	t = 0;
	for(ll i = 1; i <= n; i++){
		t += d[i];
		ans[i] = t + a[i];
	}
	for(ll i = 1; i <= n; i++)cout << ans[i] << " ";
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