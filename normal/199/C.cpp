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
	ll k, b, n, t;
	cin >> k >> b >> n >> t;
	if(k == 1){
		ll z = 1, nn = 0;
		for(ll i = 0; i < n; i++)z = k*z+b;
		while(t < z){
			t = k*t+b;
			nn++;
		}
		cout << nn;
		return;
	}
	ll diff = 0, tk = 1, ans = 0;
	while(tk < t and diff <= n){
		if(b*(1-tk)/(k-1)+(t-tk) >= 0)ans = diff;
		tk *= k;
		diff++;
	}
	cout << n-ans;
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