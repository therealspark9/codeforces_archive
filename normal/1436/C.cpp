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

vll fact(2000, 0), invfact(2000, 0);

ll f(ll x){return fact[x];}
ll fi(ll x){return invfact[x];}

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll ncr(ll n, ll r){
	if(r>n)return 0;
	ll ans = (f(n)*fi(r))%mod;
	ans = (ans*fi(n-r))%mod;
	return ans;
}

void solve(){
	fact[0] = 1, invfact[0]=1;
	for(ll i = 1; i < 2000; i++){
		fact[i] = (i*fact[i-1])%mod;
		invfact[i] = binpow(fact[i], mod-2);
	}
	ll n, x, pos;
	cin >> n >> x >> pos;
	ll l = 0, r = n, s = 0, b = 0;
	while(l < r){
		ll m = (l+r)/2;
		if(m <= pos){
			if(m != pos)s++;
			l=m+1;
		}
		else if(m > pos)b++, r=m;
	}
	// cout << b;
	ll ans = (ncr(n-x, b)*ncr(x-1, s))%mod;
	// cout << ncr(n-x,b);
	ans = (ans*f(s))%mod;
	ans = (ans*f(b))%mod;
	ans = (ans*f(n-1-s-b))%mod;
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