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
	ll n, p, k, pt, pp;
	cin >> n >> p >> k;
	string s;
	cin >> s;
	cin >> pt >> pp;
	vll dp(n);
	for(auto &it:dp)it = inf;
	dp[p-1] = 0;
	for(ll i = p-1; i < n; i++){
		ll x = 0, z = inf;
		if(s[i] == '0') x = pt;
		if(i-k >= p-1)z = dp[i-k];
		dp[i] = z + x;
		dp[i] = min(dp[i], x + pp*(i-(p-1)));
	}
	ll ans = inf;
	for(ll i = 0; i < n; i++)if(i+k >= n)ans = min(ans, dp[i]);
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