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
	ll n;
	cin >> n;
	for(ll i = 1; i <= n; i++){
		ll rep = n-(i-1), ans = 10;
		if(rep <= 2){
			if(rep == 2)ans = (ans*9)%mod;
			ans = (ans*rep)%mod;
		}
		else{
			ans = (ans*9)%mod;
			ans = (ans*binpow(10ll, n-(i+1)))%mod;
			ans = (ans*2)%mod;
			ans = (ans + (((10ll*binpow(9ll, 2ll)*binpow(10ll, n-(i+2)))%mod)*(rep-2))%mod)%mod;
		}
		cout<<ans<<" ";
	}
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