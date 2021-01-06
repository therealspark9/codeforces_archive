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

ll const nax = 1e4;
vll f(nax, 0), fi(nax, 0);

ll binpow(ll a, ll b){
	a %= mod;
	ll res = 1;
	while(b){
		if(b&1) res = res*a%mod;
		a = a*a%mod;
		b >>=1;
	}
	return res;
}

ll ncr(ll n, ll r){
	ll res = f[n]*fi[n-r]%mod;
	res = res*fi[r]%mod;
	return res;
}

void solve(){
	f[0] = fi[0] = 1;
	for(ll i = 1; i < nax; i++){
		f[i] = i*f[i-1]%mod;
		fi[i] = binpow(f[i],mod-2);
	}
	ll n;
	cin >> n;
	vll a(n);
	for(ll i = 0; i < n; i++)cin >> a[i];
	ll x = 1, ans = 1;
	for(auto it:a){
		ans = ans*ncr(x+it-2,it-1)%mod;
		x+=it;
	}
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
  return 0;
}