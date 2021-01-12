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
	ll n, p;
	cin >> n >> p;
	vector<pll> a(n);
	double num = 0, price = 2000;
	for(auto &it:a)cin>>it.f>>it.s;
	for(ll i = 0; i < n; i++){
		ll j = (i+1)%n;
		ll l = a[i].s/p - (a[i].f-1)/p, r = a[j].s/p - (a[j].f-1)/p, tl = a[i].s-a[i].f+1, tr = a[j].s-a[j].f+1;
		ll tnum = l*(tr-r) + r*(tl-l) + l*r;
		num += tnum*price/(tr*tl);
	}
	cout << num;
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