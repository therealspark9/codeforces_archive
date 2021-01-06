//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, c;

void input(){
	cin >> n >> c;
}

void solve(){
	vll a(n,0), b(n,0);
	for(ll i = 1; i < n; i++)cin >> a[i];
	for(ll i = 1; i < n; i++)cin >> b[i];
	ll dp[2][n];
	for(ll i = 0; i < 1; i++)for(ll j = 0; j < n; j++)dp[i][j] = inf;
	dp[0][0] = dp[1][0] = 0;
	dp[0][1] = a[1];
	dp[1][1] = b[1]+c;
	for(ll i = 2; i < n; i++){
		dp[0][i] = min({dp[0][i-1]+a[i], dp[1][i-1]+a[i]});
		dp[1][i] = min({dp[0][i-1]+b[i]+c, dp[1][i-1]+b[i]});
	}
	for(ll i = 0; i < n; i++)cout << min(dp[0][i], dp[1][i]) << " ";
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