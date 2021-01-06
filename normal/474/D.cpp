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

ll const nax = 1e5+5;
ll n, k;
vll dp(nax, 0);

void input(){
	cin >> n >> k;
}

void solve(){
	dp[0] = 1;
	for(ll i = 1; i < nax; i++){
		dp[i] = dp[i-1];
		if(i-k>=0)dp[i] = (dp[i]+dp[i-k])%mod;
	}
	for(ll i = 1; i < nax; i++)dp[i] = (dp[i-1] + dp[i])%mod;
	for(ll i = 0; i < n; i++){
		ll u, v;
		cin >> u >> v;
		cout << (dp[v] - dp[u-1] + mod) % mod<< endl;
	}
		
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