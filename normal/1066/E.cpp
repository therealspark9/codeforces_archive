//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 998244353
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n, M;

void input(){
	cin >> n >> M;
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve(){
	string a, b;
	cin >> a >> b;
	ll x = 0, y = 0;
	for(ll i = 0; i < n; i++)if(a[i] == '1') x = (x + binpow(2, n - i - 1, mod))%mod; 
	for(ll i = 0; i < M; i++)if(b[i] == '1') y = (y + binpow(2, n - i - 1, mod))%mod;
	ll ans = 0;
	while(y){
		ans = (ans + (x&y))%mod;
		y = y>>1;
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
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}