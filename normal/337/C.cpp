//May the force be with me
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000009
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

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
	ll n, m, k;
	cin >> n >> m >> k;
	ll wr = n-m;
	ll left = m-wr*(k-1);
	ll ans = min(m, m - left);
	ll tans = 0;
	if(left > 0){
		if(left/k > 0)tans = (((binpow(2, left/k + 1) - 2 + mod)%mod)*k)%mod;
		tans = (tans + left%k)%mod;
	}
	cout<<(ans+tans)%mod;
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