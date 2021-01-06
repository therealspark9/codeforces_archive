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

vll fact(1ll*1e6+5), facti(1ll*1e6+5);

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
	ll a, b, n;
	cin >> a >> b >> n;
	fact[0] = facti[0] = 1;
	for(ll i = 1; i < sz(fact); i++){
		fact[i] = i*fact[i-1]%mod;
		facti[i] = binpow(fact[i], mod-2);
	}
	ll ans = 0;
	for(ll i = 0; i <= n; i++){
		ll su = a*i + (n-i)*b;
		bool f = true;
		while(su){
			if(su%10 == a or su%10 == b)f &= true;
			else f = false;
			su /= 10;
		}
		if(f){
			ll mul = facti[i]*facti[n-i]%mod;
			mul = mul*fact[n]%mod;
			ans += mul;
			ans %= mod;
		}
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
  return 0;
}