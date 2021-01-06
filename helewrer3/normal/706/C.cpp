//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >>  it;
	string s[n];
	for(auto &it:s)cin >> it;
	ll dp[2][n];
	for(ll i = 0; i < n; i++)dp[0][i] = dp[1][i] = inf;
	dp[0][0] = 0, dp[1][0] = a[0];
	for(ll i = 1; i < n; i++){
		string x = s[i], y = s[i-1];
		reverse(all(x)), reverse(all(y));
		if(s[i] >= s[i-1])dp[0][i] = min(dp[0][i], dp[0][i-1]);
		if(s[i] >= y)dp[0][i] = min(dp[0][i], dp[1][i-1]);
		if(x >= s[i-1])dp[1][i] = min(dp[1][i], dp[0][i-1] + a[i]);
		if(x >= y)dp[1][i] = min(dp[1][i], dp[1][i-1] + a[i]);
	}
	if(min(dp[0][n-1], dp[1][n-1]) != inf)cout << min(dp[0][n-1], dp[1][n-1]);
	else cout << -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}