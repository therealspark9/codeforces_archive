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
const ll nax = 1.5 * 1e7+5;
vll ispr(nax);
vll v(nax);
void sieve(ll x){
	for(ll i = 0; i <= x; i++)ispr[i] = i;
	ispr[1] = 0;
	for(ll i = 2; i*i <= x; i++) if(ispr[i] == i)for(ll j = i*i; j <= x; j+= i)ispr[j] = i;
}

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	ll x = a[0], y = 0;
	for(auto it:a)x = __gcd(it, x);
	for(auto &it:a)it/=x;
	for(auto it:a)y = max(it, y);
	sieve(nax-1);
	for(auto &it:v)it = 0;
	for(auto it:a){
		set<ll> b;
		while(it != 1){
			b.insert(ispr[it]);
			it /= ispr[it];
		}
		for(auto jt:b)v[jt]++;
	}
	ll ans = n-1;
	for(auto it:v)ans = min(ans, n - it);
	bool f = true;
	for(auto it:a)if(it != 1)f = false;
	if(f) cout << -1;
	else cout << ans;
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