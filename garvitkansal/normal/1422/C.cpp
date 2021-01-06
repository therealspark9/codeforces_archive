/*May the force be with me*/
#include "bits/stdc++.h"
#define endl "\n"
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

void solve(){
	ll n, m, ans = 0;
	cin >> n >> m;
	ll a[n][m];
	for(ll i = 0; i < n; i++) for(ll j = 0; j < m; j++) cin >> a[i][j];
	for(ll i = 0; i < n/2; i++) for(ll j = 0; j < m/2; j++){
		ll x = (a[i][j] + a[n-1-i][j] + a[i][m-1-j] + a[n-1-i][m-1-j])/4;
		ll tans = 0, tans1 = 0;
		tans += abs(a[i][j] - x);
		tans += abs(a[n-1-i][j] - x); 
		tans += abs(a[i][m-1-j] - x); 
		tans += abs(a[n-1-i][m-1-j] - x);
		tans1 += abs(a[i][j] - (x+1));
		tans1 += abs(a[n-1-i][j] - (x+1)); 
		tans1 += abs(a[i][m-1-j] - (x+1)); 
		tans1 += abs(a[n-1-i][m-1-j] - (x+1));
		ans += min(tans, tans1);
	}
	if(n%2){
		for(ll i = 0; i < m/2; i++){
			ll x = a[n/2][i] + a[n/2][m-1-i];
			x/=2;
			ll tans = 0, tans1 = 0;
			tans = abs(a[n/2][i] - x) + abs(a[n/2][m-1-i] - x);
			tans1 = abs(a[n/2][i] - (x+1)) + abs(a[n/2][m-1-i] - (x+1));
			ans += min(tans, tans1);
		}
	}
	if(m%2){
		for(ll i = 0; i < n/2; i++){
			ll x = a[i][m/2] + a[n-1-i][m/2];
			x/=2;
			ll tans = 0, tans1 = 0;
			tans = abs(x- a[i][m/2]) + abs(x- a[n-1-i][m/2]);
			tans1 = abs(1+x- a[i][m/2]) + abs(1+x- a[n-1-i][m/2]);
			ans += min(tans, tans1);
		}
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}