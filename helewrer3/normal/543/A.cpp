//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
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

ll dp[500+1][500+1], num[500+1][500+1];
void solve(){
	ll n, m, b, mod;
	cin >> n >> m >> b >> mod;
	vll a(n);
	for(auto &it:a)cin>>it;
	for(ll i = 0; i <= m; i++) for(ll j = 0; j <= b; j++) dp[i][j] = 0;
	for(ll i = 0; i < n; i++) num[0][i] = 1;
	for(ll i = 1; i <= m; i++){
		for(ll j = b; j >= 0; j--){
			for(ll k = 0; k < n; k++){
				num[j][k] = 0;
				if(k)num[j][k] = (num[j][k]+num[j][k-1])%mod;
				if(j-a[k]<0)continue;
				num[j][k] = 0;
				dp[i][j-a[k]] = (dp[i][j-a[k]] + num[j-a[k]][k])%mod;
				num[j][k] = (num[j][k] + num[j-a[k]][k])%mod;
				if(k)num[j][k] = (num[j][k]+num[j][k-1])%mod;
			}
		}
	}
	ll ans = 0;
	for(ll i = 0; i <= b; i++) ans = (ans + dp[m][i])%mod;
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t = 1;
	//cin >> t;
	while(t--) solve();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi