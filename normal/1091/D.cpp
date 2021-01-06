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

vll f(1ll*1e6+5);

ll ans(ll n){
	if(n == 1)return 1;
	return n*(ans(n-1)+f[n-1]-1)%mod;
}

void solve(){
	f[0] = 1;
	for(ll i = 1; i < sz(f); i++)f[i] = i*f[i-1]%mod;
	ll n;
	cin >> n;
	cout << ans(n);
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