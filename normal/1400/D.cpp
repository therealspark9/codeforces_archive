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

void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	ll mp[n*n+n+5] = {0};
	ll ans = 0;
	for(ll i = n-1; i >= 0; i--){
		for(ll j = i+2; j < n; j++)mp[n*a[i+1]+a[j]]++;
		for(ll j = 0; j < i; j++)ans += mp[n*a[j]+a[i]];
	}
	cout<<ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);
  ll t = 1;
  cin >> t;
  while(t--){
    solve();
    cout << endl;
  }
  return 0;
}