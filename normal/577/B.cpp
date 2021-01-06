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
	ll n, m;
	cin >> n >> m;
	vll a(n);
	for(auto &it:a)cin>>it;
	if(n>m)cout<<"YES";
	else{
		ll dp[n+1][m+1];
		for(ll i = 0; i <= n; i++)for(ll j = 0; j <= m; j++)dp[i][j]=0;
		dp[0][0] = 1;
		for(ll i = 1; i <= n; i++){
			for(ll j = 0; j <= m; j++){
				dp[i][j] = max(dp[i-1][j], dp[i-1][(j+a[i-1])%m]);
			} 
		}
		if(dp[n][m])cout<<"YES";
		else cout<<"NO";
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
  return 0;
}