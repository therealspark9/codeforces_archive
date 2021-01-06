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

map<pll, ll> mp;

void solve(){
	ll n, m, K;
	cin >> n >> m >> K;
	vll a(n+1, 0);
	for(ll i = 1; i < n+1; i++)cin>>a[i];
	for(ll i = 0; i < K; i++){
		ll u, v, c;
		cin >> u >> v >> c;
		mp[{u, v}] = c;
	}
	ll st = (1ll<<n)/n;
	pll dp[n+1][n+1][st+1];
	for(ll i = 0; i <= n; i++) for(ll j = 0; j <= n; j++)for(ll o = 0; o <= st; o++)dp[i][j][o] = {-1,0};
	for(ll i = 1; i <= n; i++){
		dp[1][i][0].f = a[i]; 
		dp[1][i][0].s = 1ll<<i;
	}
	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			ll t = 0;
			for(ll k = 1; k <= n; k++){
				ll o = 0;
				while(o <= st and dp[i-1][k][o].f != -1){
					if((dp[i-1][k][o].s&(1ll<<j)) != 0){
						o++;
						continue;
					}
					ll x = a[j];
					if(mp.count({k, j})) x+=mp[{k, j}];
					dp[i][j][t].f = dp[i-1][k][o].f + x;
					dp[i][j][t].s = dp[i-1][k][o].s|(1ll<<j);
					t++, o++;
				}
			}
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j <= st; j++){
			pll it = dp[m][i][j];
			// if(it.f > ans)cout << it.s << " ";
			ans = max(ans, it.f);
			// cout << it << " ";
		}
	}
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