//May the force be with me
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
#define endl "\n"
using namespace std;

ll nax = 3ll*1e5+5;
vll f(nax), fi(nax);

ll binpow(ll a,ll b){
	a %= mod;
	ll res = 1;
	while(b){
		if(b&1)res = (res*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

void solve(){
	f[0] = fi[0] = 1;
	for(ll i = 1; i < nax; i++){
		f[i] = (i*f[i-1])%mod;
		fi[i] = binpow(f[i],mod-2);
	}
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	if(n <= 2){
		cout << 0;
		return;
	}
	for(ll i = n-1; i <= m; i++){
		ll mul = f[i-1];
		mul = (mul*fi[n-3])%mod;
		mul = (mul*fi[i-n+1])%mod;
		mul = (mul*binpow(2, n-3))%mod;
		ans = (ans+mul)%mod;
	}
	//ans = (f[m]*fi[n-1])%mod;
	//ans = (ans*fi[m-n+1])%mod;
	//ans = (ans*(n-2))%mod;
	//ans = (ans*binpow(2,n-3))%mod;
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
  return 0;
}