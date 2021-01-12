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

bool mc(pair<ll, pll> a, pair<ll, pll> b){
	if(a.f == b.f)return a.s.f < b.s.f;
	return a.f > b.f;
}

void solve(){
	ll n, m;
	cin >> n >> m;
	vector<pll> a(m+1), vis(m+1);
	for(ll i = 1; i <= m; i++)cin >> a[i].f >> a[i].s;                                                                         
	for(ll i = 1; i <= m; i++)vis[i].f = vis[i].s = 0;
	vector<pair<ll, pll>> b;
	for(ll i = 1; i <= m; i++){
		b.pb({a[i].f, {1, i}});
		b.pb({a[i].s, {2, i}});
	}
	sort(all(b), mc);
	ll ans = 0, su = 0, t = 0;
	for(ll i = 0; i < sz(b); i++){
		if(b[i].s.f == 1){
			su += b[i].f;
			t++;
			if(t > n){
				ans = max(ans, su - b[i].f);
				break;
			}
		}
		else if(b[i].s.f == 2){
			if(vis[b[i].s.s].f) ans = max(ans, su + (n-t)*b[i].f);
			else ans = max(ans, su + (n-(t+1))*b[i].f + a[b[i].s.s].f);
		}
		if(b[i].s.f == 1)vis[b[i].s.s].f = 1;
		else vis[b[i].s.s].s = 1;
	}
	cout << ans;
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
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi