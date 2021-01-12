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

ll const nax = 3*1e5+5;
vll ls[nax], vis(nax,0), mp(nax,0), mppr(nax,0);

void solve(){
	ll n, m;
	cin >> n >> m;
	vll a(n);
	vector<pll> b(m);
	for(auto &it:a)cin >> it;
	for(ll i = 0; i < n; i++)mp[a[i]]=i;
	for(auto &it:b)cin >> it.f >> it.s;
	for(ll i = 0; i < m; i++){
		ls[b[i].s].pb(i), ls[b[i].f].pb(i);
		mppr[i] = min(mp[b[i].f], mp[b[i].s]);
	}
	ll l = 0, r = 0, pr = 0, ans = n;
	while(r < n){
		vll c;
		bool f = false;
		ll mxl = -1;
		for(auto it:ls[a[r]]){
			if(vis[it])mxl = max(mxl, mppr[it]);
			f |= vis[it];
			vis[it]=1;
		}
		if(f){
			ans = ans+(r-l)*(r-l-1)/2 - (pr-l)*(pr-l-1)/2;
			while(l <= mxl){
				for(auto it:ls[a[l]])vis[it]=0;
				l++;
			}
			pr = r;
		}
		r++;
	}
	ans = ans+(r-l)*(r-l-1)/2 - (pr-l)*(pr-l-1)/2;
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