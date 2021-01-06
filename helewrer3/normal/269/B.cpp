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
	ll n, k;
	cin >> n >> k;
	vll a(n);
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		double d;
		cin >> d;
	}
	ll ans = n;
	vll dp(n, 0);
	for(ll i = 0; i < n; i++){
		dp[i] = 1;
		for(ll j = i-1; j >= 0; j--) if(a[j] <= a[i]) dp[i] = max(dp[j]+1, dp[i]);
	}
	for(auto it:dp)ans = min(ans, n - it);
	cout << ans;
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