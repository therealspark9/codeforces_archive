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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	vll cum(3*d, 0);
	for(ll i = b; i <= c; i++){
		ll l = i+a, r = i+b;
		cum[l-1]--, cum[r]++;
	}
	for(ll i = 2*d; i >= 0; i--)cum[i]+=cum[i+1];
	for(ll i = 2*d; i >= 0; i--)cum[i]+=cum[i+1];
	ll ans = 0;
	for(ll i = c; i <= d; i++) ans += cum[i+1];
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