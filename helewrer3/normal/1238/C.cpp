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
	ll h, n;
	cin >> h >> n;
	vll a(n);
	for(auto &it:a)cin >> it;
	vll dp(n);
	for(ll i = 0; i < n; i++)dp[i] = inf;
	dp[0] = 0;
	for(ll i = 1; i < n; i++){
		if(a[i-1] >= a[i]+1) dp[i] = dp[i-1] + 1;
		if(a[i]+2 > h)continue;
		if(a[i-1] >= a[i]+2)dp[i] = min(dp[i], dp[i-1] + 1);
		else if(i-2 >= 0) dp[i] = min(dp[i], dp[i-2]);
	}
	if(a[n-1] >= 2) cout << dp[n-1];
	else cout << min(dp[n-1], dp[n-2]);
	
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