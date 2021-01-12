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

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	mll b;
	for(auto &it:a)cin>>it;
	for(ll i = 0; i < n; i++)b[a[i]] = max(b[a[i]],i);
	ll ans = 1, l = b[a[0]];
	for(ll i = 0; i < n; i++){
		if(l < i)ans = ans*2%mod;
		l = max(l, b[a[i]]);
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