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

ll n, m;
ll dp[1001][11] = {0};

void input(){
	cin >> n >> m;
}

void solve(){
	for(ll i = 0; i < 1001; i++)dp[i][0] = 1;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			for(ll k = 1; k <= i; k++) dp[i][j] = (dp[i][j] + dp[k][j-1]*(i-k+1))%mod;
		}
	}
	cout<<dp[n][m];
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