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
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	pll c;
	vll d;
	//0
	c.f = 1+a;
	for(ll i = 0; i < n; i++){
		c.s = (i*k+1)+b;
		d.pb(abs(c.s - c.f));
	}
	//1
	c.f = (k+1)-a;
	for(ll i = 0; i < n; i++){
		c.s = (i*k+1)+b;
		d.pb(abs(c.s - c.f));
	}
	//2
	c.f = (k+1)-a;
	for(ll i = 1; i <= n; i++){
		c.s = (i*k+1)-b;
		d.pb(abs(c.s - c.f));
	}
	//3
	c.f = 1+a;
	for(ll i = 1; i <= n; i++){
		c.s = (i*k+1)-b;
		d.pb(abs(c.s - c.f));
	}
	ll ans1 = inf, ans2 = -inf;
	if(a==b)ans1 = 1;
	for(ll i = 0; i < sz(d); i++){
		if(d[i] <= 0)continue;
		ans1 = min(ans1, (n*k*d[i])/__gcd(n*k, d[i])/d[i]); 
		ans2 = max(ans2, (n*k*d[i])/__gcd(n*k, d[i])/d[i]);
	}
	cout << ans1 << " " << ans2;
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