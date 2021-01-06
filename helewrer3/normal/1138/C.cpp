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

mll mpr[1000];
mll mpc[1000];
vll vr(1000, 0), vc(1000, 0);

void solve(){
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin >> a[i][j];
	for(ll i = 0; i < n; i++){
		set<ll> s;
		for(ll j = 0; j < m; j++) s.insert(a[i][j]);
		ll t = 1;
		while(!s.empty()){
			ll v = (*s.begin());
			s.erase(s.begin());
			mpr[i][v] = t;
			vr[i] = t;
			t++;
		}
	}
	for(ll j = 0; j < m; j++){
		set<ll> s;
		for(ll i = 0; i < n; i++) s.insert(a[i][j]);
		ll t = 1;
		while(!s.empty()){
			ll v = (*s.begin());
			s.erase(s.begin());
			mpc[j][v] = t;
			vc[j] = t;
			t++;
		}
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			ll ans = max(vc[j], vr[i]);
			ll d = abs(mpr[i][a[i][j]] - mpc[j][a[i][j]]);
			if(mpr[i][a[i][j]] > mpc[j][a[i][j]]) ans = max(ans, vc[j] + d);
			else if(mpr[i][a[i][j]] < mpc[j][a[i][j]]) ans = max(ans, vr[i] + d);
			cout << ans << " ";
		}
		cout<<endl;
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