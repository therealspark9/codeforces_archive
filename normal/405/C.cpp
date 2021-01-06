/*May the force be with me*/
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

ll n, q;
ll const nax = 1005;
ll a[nax][nax];

void input(){
	cin >> n;
}

void solve(){
	for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++)cin >> a[i][j];
	ll b[4][n], ans = 0, cntr[n], cntc[n], curr[n];
	for(ll i = 0; i < n; i++)cntr[i] = 0;
	for(ll i = 0; i < n; i++)cntc[i] = 0;
	for(ll i = 0; i < n; i++)curr[i] = 0;
	for(ll i = 0; i < n; i++){
		ll d = 0;
		for(ll j = 0; j < n; j++) d += a[i][j]*a[j][i]; //og
		b[0][i] = d;
		d = 0;
		for(ll j = 0; j < n; j++) d += (1 - a[i][j])*(a[j][i]); //row
		b[1][i] = d;
		d = 0;
		for(ll j = 0; j < n; j++) d += (a[i][j])*(1 - a[j][i]); //col
		b[2][i] = d;
		d = 0;
		for(ll j = 0; j < n; j++) d += (1 - a[i][j])*(1 - a[j][i]); //row and col
		b[3][i] = d;
		ans += b[0][i];
		curr[i] = b[0][i];
	}
	cin >> q;
	ans %= 2;
	while(q--){
		ll t; cin >> t;
		if(t == 3){cout << ans%2; continue;}
		else {
			ll d;
			cin >> d;
			ans = 1 - ans;
		}
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