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

bool mc(pll p1, pll p2){
	if(p1.f == p2.f)return p1.s < p2.s;
	return p1.f < p2.f;
}

void solve(){
	ll n;
	cin >> n;
	vll fac(n+1, 0);
	fac[0] = 1;
	for(ll i = 1; i <= n; i++)fac[i] = (fac[i-1]*i)%mod;
	vector<pll> a(n);
	for(auto &it:a)cin>>it.f>>it.s;
	ll ans = fac[n];
	vll tf(n+1,0), ts(n+1,0);
	for(auto it:a)tf[it.f]++, ts[it.s]++;
	ll ff = 1, fs = 1, ffs = 1;
	for(auto it:tf) ff = (ff*fac[it])%mod;
	for(auto it:ts) fs = (fs*fac[it])%mod;
	ans = (ans - ff + mod)%mod;
	ans = (ans - fs + mod)%mod;
	sort(all(a), mc);
	ll i = 0;
	bool f = true;
	for(ll j = 0; j < n-1; j++)if(a[j].s > a[j+1].s)f = false;
	if(!f) i = n+1, ffs = 0;
	vll temts(n+1, 0), vis(n+1, 0);
	while(i < n){
		vll s;
		for(ll j = i; j < i+tf[a[i].f]; j++){
			if(!vis[a[j].s])s.pb(a[j].s);
			vis[a[j].s] = 1, temts[a[j].s]++;
		}
		for(auto it:s){
			ffs = (ffs*fac[temts[it]])%mod;
			vis[it] = 0, temts[it] = 0;
		}
		i+=tf[a[i].f];
	}
	ans = (ans + ffs)%mod;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi