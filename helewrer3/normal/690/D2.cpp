//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000003
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


ll nax = 2*1e6+5;
vll f(nax), fi(nax);

ll ncr(ll n, ll r){
	ll res = fi[n-r]*fi[r]%mod;
	res = res*f[n]%mod;
	return res;
}

ll binpow(ll a, ll b){
	a%=mod;
	ll res = 1;
	while(b){
		if(b&1)res = res*a%mod;
		a = a*a%mod;
		b>>=1;
	}
	return res;
}

void solve(){
	f[0] = fi[0] = 1;
	for(ll i = 1; i < nax; i++){
		f[i] = i*f[i-1]%mod;
		fi[i] = binpow(f[i],mod-2);
	}
	ll n, c;
	cin >> n >> c;
	ll ans = 0;
	for(ll i = 1; i <= n; i++) ans = (ans+ncr(i+c-1,c-1))%mod;
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