//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 998244353
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n, k;
ll dp[1005][2010][4]; //ww, wb, bw, bb

void input(){
	cin >> n >> k;
}

void solve(){
	memset(dp, 0, sizeof(dp));
	dp[1][1][0] = dp[1][1][3] = 1;
	dp[1][2][1] = dp[1][2][2] = 1;
	for(ll i = 2; i <= n; i++){
		for(ll j = 1; j <= k; j++){
			dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3])%mod;
			dp[i][j][3] = (dp[i][j][3] + dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3])%mod;
			if(j-2>=0){
				dp[i][j][1] = (dp[i][j][1] + dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j-2][2] + dp[i-1][j-1][3])%mod;
				dp[i][j][2] = (dp[i][j][2] + dp[i-1][j-1][0] + dp[i-1][j][2] + dp[i-1][j-2][1] + dp[i-1][j-1][3])%mod;
			}
		}
	}
	ll ans = (dp[n][k][0]+dp[n][k][2]+dp[n][k][3]+dp[n][k][1])%mod;
	cout<<ans;
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