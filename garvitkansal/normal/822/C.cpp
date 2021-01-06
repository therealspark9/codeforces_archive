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

ll const nax = 2 * 1e5 + 5;
vll c[nax], b[nax];

bool mc(pair<pll, ll> p1, pair<pll, ll> p2){
	return p1.f.f < p2.f.f;
}


void solve(){
	ll n, x;
	cin >> n >> x;
	vector<pair<pll, ll>> a(n);
	for(auto &it:a)cin >> it.f.f >> it.f.s >> it.s;
	sort(all(a), mc);
	for(ll i = 0; i < n; i++)c[a[i].f.s - a[i].f.f + 1].pb(i);
	for(ll i  = 0; i < nax; i++){
		if(!sz(c[i]))continue;
		b[i].resize(sz(c[i]));
		b[i].back() = a[c[i].back()].s;
		for(ll j = sz(c[i])-2; j >= 0; j--)b[i][j] = min(b[i][j+1], a[c[i][j]].s);
	}
	ll ans = inf;
	for(ll i = 0; i < n; i++){
		ll k = a[i].f.s - a[i].f.f + 1;	
		if(k >= x or !sz(c[x-k]))continue;
		ll l = 0, r = sz(c[x-k]) - 1;
		while(l <= r){
			ll mid = l + (r-l)/2;
			if(a[c[x-k][mid]].f.f <= a[i].f.s)l = mid + 1;
			else{
				ans = min(ans, a[i].s + b[x-k][mid]);
				r = mid - 1;
			}
		}
	}
	if(ans != inf)cout << ans;
	else cout << -1;
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