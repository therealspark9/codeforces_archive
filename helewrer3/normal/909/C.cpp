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
	string s;
	for(ll i = 0; i < n; i++){
		char c;
		cin >> c;
		s += c;
	}
	ll dp[n+1][n+1];
	for(ll i = 0; i < n+1; i++) for(ll j = 0; j < n+1; j++)dp[i][j] = 0;
	ll cnt = 0;
	string t = "&";
	t += s;
	dp[1][1] = 1;
	if(t[1] == 'f')cnt++;
	for(ll i = 2; i < n+1; i++){
		if(t[i] == 'f')cnt++;
		ll su = 0;
		for(ll j = 1; j <= cnt+1; j++)su = (su + dp[i-1][j])%mod;
		for(ll j = 1; j <= cnt+1; j++){
			if(t[i-1] == 'f')dp[i][j] = dp[i-1][j-1];
			else{
				dp[i][j] = su;
				su = (su - dp[i-1][j] + mod)%mod;
			}
		}
	}
	ll ans = 0;
	for(ll j = 1; j <= n; j++)ans = (ans + dp[n][j])%mod;
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