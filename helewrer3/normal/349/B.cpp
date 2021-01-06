//May the force be with me
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


void solve(){
	ll n;
	cin >> n;
	vll a(9);
	for(auto &it:a)cin>>it;
	ll mn = inf;
	for(auto it:a)mn = min(it, mn);
	if(n < mn){
		cout<<-1;
		return;
	}
	ll dp[4][n+1];
	for(ll i = 0; i <= n; i++)dp[0][i] = dp[1][i] = dp[2][i] = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < 9; j++){
			if(i-a[j] < 0)continue;
			if(dp[0][i-a[j]]+1 > dp[0][i]){
				dp[0][i] = dp[0][i-a[j]]+1;
				dp[1][i] = j+1;
				dp[2][i] = i - a[j];
				// cout << dp[0][i] << " ";
			}
			else if(dp[0][i-a[j]]+1 == dp[0][i] and dp[1][i] < j+1){
				dp[0][i] = dp[0][i-a[j]]+1;
				dp[1][i] = j+1;
				dp[2][i] = i - a[j];
			}
		}
	}
	ll k = n;
	while(k){
		if(dp[1][k])cout << dp[1][k];
		k = dp[2][k];
	}
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