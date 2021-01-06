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

ll nax = 3 * 1e5+5;
vll fac(nax+1, 0), inv(nax+1, 0);

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
	if(n < r)return 0;
	return ((fac[n]*inv[r]%mod)*inv[n-r])%mod;
}

bool mc(pll p1, pll p2){
	if(p1.f == p2.f)return p1.s > p2.s;
	return p1.f < p2.f;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<pll> a;
	for(ll i = 0; i < n; i++){
		ll l, r;
		cin >> l >> r;
		a.pb({l,1});
		a.pb({r+1,2});
	}
	sort(all(a), mc);
	ll cnt = 0, ans = 0;
	for(auto it:a){
		if(it.s == 1){
			ans = (ans+ncr(cnt, k-1))%mod;
			cnt++;
		}
		else cnt--;
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	fac[0] = 1;
	for(ll i = 1; i <= nax; i++)fac[i] = (fac[i-1]*i)%mod;
	inv[nax] = binpow(fac[nax], mod-2);
	for(ll i = nax-1; i >= 0; i--)inv[i] = (inv[i+1]*(i+1))%mod;
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