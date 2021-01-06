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

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
	vll s;
	ll ans = 1;
	ll x, n;
	cin >> x >> n;
	if(x%2 == 0) s.pb(2);
	while(x%2 == 0) x/=2;
	for(ll j = 3; j*j <= x; j+= 2){
		if(x%j == 0) s.pb(j);
		while(x%j == 0) x/=j;
	}
	if(x != 1)s.pb(x);
	for(auto it:s){
		ll v = n, prev = 1, cur = it;
		while(n/cur != 0){
			ll u = n/cur;
			v -= u;
			ans = (ans * binpow(prev, v))%mod;
			v = u;
			prev = cur;
			if(cur> (1e18)/it)break;
			cur = (cur*it);
		}
		ans = (ans * binpow(prev, v))%mod;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi