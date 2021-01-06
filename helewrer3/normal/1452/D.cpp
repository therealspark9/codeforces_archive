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
	ll n;
	cin >> n;
	ll a = 0, b = 1;
	for(ll i = 1; i <= n-1; i++){
		ll t=b;
		b+=a;
		b%=mod;
		a=t;
	}
	ll res = b;
	res = (res*binpow(binpow(2,n), mod-2))%mod;
	cout << res;
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