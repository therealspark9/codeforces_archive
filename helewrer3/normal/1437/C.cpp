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


void solve(){
	ll n;
	cin >> n;
	vll a(n+1);
	for(ll i = 1; i <= n; i++)cin >> a[i];
	a[0] = -inf;
	sort(all(a));
	ll dp[300][500];
	for(ll i = 0; i <= n; i++)for(ll j = 0; j < 500; j++)dp[i][j] = inf;
	for(ll j = 0; j < 500; j++)dp[0][j] = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j < 500; j++){
			for(ll k = 0; k < j; k++)dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(a[i] - j));
		}
	}
	ll ans = inf;
	for(ll i = 1; i < 500; i++)ans = min(ans, dp[n][i]);
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi