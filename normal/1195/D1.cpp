//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 998244353
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	ll b[n][2];
	for(ll i = 0; i < n; i++)b[i][0] = b[i][1] = 0;
	for(ll i = 0; i < n; i++){
		ll x = 10, t = a[i];
		while(t){
			b[i][1] = (b[i][1] + (x*(t%10)) % mod) % mod;
			x *= 100;
			x %= mod;
			t/=10;
		}
		x = 1, t = a[i];
		while(t){
			b[i][0] = (b[i][0] + (x*(t%10)) % mod) % mod;
			x *= 100;
			x %= mod;
			t/=10;
		}
	}
	ll su = 0;
	for(ll i = 0; i < n; i++) su = (su + b[i][0])%mod;
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		ll tans = 0;
		tans = (n*b[i][1])%mod;
		tans = (tans + su)%mod;
		ans = (ans + tans)%mod;
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
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}