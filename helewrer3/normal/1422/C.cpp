//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;


void solve(){
	string t;
	cin >> t;
	string s = " " + t;
	ll n = sz(t);
	vll a(n+1), b(n+1);
	a[0] = 1, b[0] = 0;
	for(ll i = 1; i <= n; i++)a[i] = (a[i-1]*10)%mod;
	for(ll i = 1; i <= n; i++){
		ll x = s[i]-'0';
		b[i] = ((b[i-1]*10)%mod + x)%mod;
	}
	ll ans = 0, temp = 0;
	for(ll i = 1; i <= n; i++){
		ll su = (i*(b[n] - (b[i]*a[n-i])%mod)) % mod;
		ans = (ans+su)%mod;
		ans = (ans+(temp*a[n-i])%mod)%mod;
		temp = (temp+b[i])%mod;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi