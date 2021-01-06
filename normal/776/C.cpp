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

ll cnt(vll a, ll k){
	ll ans = 0;
	mll mp;
	mp[0] = 1;
	ll sum = 0;
	for(auto it:a){
		sum += it;
		if(mp.count(sum-k))ans += mp[sum-k];
		mp[sum]++;
	}
	return ans;
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vll a(n);
	for(auto &it:a)cin>>it;
	ll ans = 0;
	if(abs(k) > 1){
		ll tk = 1;
		while(tk <= 1ll*1e14){
			ans += cnt(a,tk);
			tk *= k;
		}
	}
	else if(abs(k) == 1){
		ans += cnt(a,1);
		if(k == -1) ans += cnt(a,-1);
	}
	else ans += cnt(a,0);
	cout << ans;
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