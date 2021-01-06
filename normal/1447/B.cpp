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
	ll a[n][m];
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)cin>>a[i][j];
	ll neg = 0, z = 0;
	for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++){if(a[i][j] < 0)neg++;if(a[i][j] == 0)z++;}
	if(neg%2 == 0 or (neg%2 and z)){
		ll ans = 0;
		for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)ans += abs(a[i][j]);
		cout<<ans;
	}
	else{
		ll ans = 0;
		for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)ans += abs(a[i][j]);
		ll mn = inf;
		for(ll i = 0; i < n; i++)for(ll j = 0; j < m; j++)mn = min(mn, abs(a[i][j]));
		cout<<ans-2*mn;
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