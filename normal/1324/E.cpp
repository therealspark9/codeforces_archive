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
	ll n, h, l, r;
	cin >> n >> h >> l >> r;
	vll a(n);
	for(auto &it:a)cin>>it;
	ll dp[n][h], vis[n][h];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < h; j++)dp[i][j] = 0;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < h; j++)vis[i][j] = 0;
	vis[0][a[0]] = vis[0][a[0]-1] = 1;
	if(a[0] >= l  and a[0] <= r)dp[0][a[0]] = 1;
	if(a[0]-1 >= l  and a[0]-1 <= r)dp[0][a[0]-1] = 1;
	for(ll i = 0; i < n-1; i++){
		for(ll j = 0; j < h; j++){
			if(!vis[i][j])continue;
			ll x;
			if((j+a[i+1])%h >= l and (j+a[i+1])%h <= r)x = 1;
			else x = 0;
			dp[i+1][(j+a[i+1])%h] = max(dp[i+1][(j+a[i+1])%h], dp[i][j]+x);
			if((j+a[i+1]-1+h)%h >= l and (j+a[i+1]-1+h)%h <= r)x = 1;
			else x = 0;
			dp[i+1][(j+a[i+1]-1+h)%h] = max(dp[i+1][(j+a[i+1]-1+h)%h], dp[i][j]+x);
			vis[i+1][(j+a[i+1])%h] = vis[i+1][(j+a[i+1]-1+h)%h] = 1;
		}
	}
	ll ans = 0;
	for(ll i = 0; i < h; i++)ans = max(ans, dp[n-1][i]);
	cout<<ans;
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