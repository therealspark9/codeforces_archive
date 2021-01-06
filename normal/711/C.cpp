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


void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	vll a(n+1);
	ll b[n+1][m+1];
	for(ll i = 1; i <= n; i++)cin>>a[i];
	for(ll i = 1; i <= n; i++)for(ll j = 1; j <= m; j++)cin>>b[i][j];
	ll dp[n+1][k+1][m+1];
	for(ll i = 0; i <= n; i++) for(ll j = 0; j <= k; j++) for(ll l = 0; l <= m; l++) dp[i][j][l] = inf;
	for(ll l = 0; l <= m; l++) dp[0][0][l] = 0;
	//1st element
	if(a[1])dp[1][1][a[1]] = 0;
	else for(ll i = 1; i <= m; i++)dp[1][1][i] = b[1][i];
	//rest
	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			if(a[i]){
				dp[i][j][a[i]] = dp[i-1][j][a[i]];
				for(ll r = 1; r <= m; r++){
					if(r == a[i]) continue;
					dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i-1][j-1][r]);
				}
				continue;
			}			
			for(ll l = 1; l <= m; l++){
				dp[i][j][l] = dp[i-1][j][l] + b[i][l];
				for(ll r = 1; r <= m; r++){
					if(r == l) continue;
					dp[i][j][l] = min(dp[i][j][l], dp[i-1][j-1][r] + b[i][l]);
				}
			}
		}
	}
	ll ans = inf;
	for(ll l = 0; l <= m; l++) ans = min(ans, dp[n][k][l]);
	if(ans == inf) cout<<-1;
	else cout<<ans;
	
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