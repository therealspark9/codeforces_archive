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
	ll n, k;
	cin >> n >> k;
	vll a(n), b(k);
	for(auto &it:a)cin >> it;
	for(auto &it:b)cin >> it;
	sort(rall(a));
	ll l = 0;
	ll ans = 0;
	for(auto it:a){
		if(it-1 <= l) ans += b[it-1];
		else ans += b[l], l++;
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