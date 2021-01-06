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
	ll a[n+1][n+1];
	vll b[n+1];
	for(ll i = 0; i <= n; i++)for(ll j = 0; j <= n; j++)a[i][j] = 0;
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		a[u][v] = 1;
		b[u].pb(v);
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(i!=j){
				ll cnt = 0;
				for(ll k = 0; k < sz(b[i]); k++){
					if(a[b[i][k]][j]) cnt++;
				}
				ans += cnt*(cnt-1)/2;
			}
		}
	}
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
  return 0;
}