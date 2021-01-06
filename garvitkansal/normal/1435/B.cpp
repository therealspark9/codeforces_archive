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
	vll a[n], b[m];
	vll ord;
	vll mp(n*m+1);
	for(ll i = 0; i < n; i++){
		a[i].resize(m);
		for(ll j = 0; j < m; j++){
			cin >> a[i][j];
			mp[a[i][j]] = i;
		}
	}
	for(ll i = 0; i < m; i++){
		b[i].resize(n);
		for(ll j = 0; j < n; j++)cin >> b[i][j];
	}
	for(ll i = 0; i < n; i++){
		ll key = b[0][i];
		ord.pb(mp[key]);
	}
	for(auto it:ord){
		for(auto jt:a[it])cout << jt << " ";
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi