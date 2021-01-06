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

ll nax = 3ll*1e5+5;
vll f(nax);

void solve(){
	ll n, m;
	cin >> n >> m;
	f[0] = 1;
	for(ll i = 1; i < nax; i++) f[i] = f[i-1]*i%m;
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ans += (n-i+1)*(f[i]*f[n-i+1]%m);
		ans %= m;
	}
	cout<<ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t = 1;
  //cin >> t;
  while(t--){
    solve();
    cout << endl;
  }
  return 0;
}