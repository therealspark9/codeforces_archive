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

vll fact(2ll*1e5+5, 0), invfact(2ll*1e5+5, 0);

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
	ll n, k, m;
	m = 3, k = 2;
	cin >> n >> m >> k;
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(all(a));
	ll ans = 0;
	if(m == 1){
		cout << n;
		return;
	}
	for(ll i = 0; i < n; i++){
		ll l = i+1, r = n-1, midd = -1;
		while(l <= r){
			ll mid = (l+r)/2;
			if(a[mid] > a[i]+k)r = mid-1;
			else l = mid+1, midd = mid;
		}
		if(midd != -1) ans = (ans+ncr(midd-i, m-1))%mod;
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	fact[0] = 1, invfact[0]=1;
	for(ll i = 1; i < sz(fact); i++){
		fact[i] = (i*fact[i-1])%mod;
		invfact[i] = binpow(fact[i], mod-2);
	}
	ll t = 1;
	cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi