//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
using namespace std;

ll n, m;

void input(){
	cin >> n;
}

bool mc(pair<pll, ll> a, pair<pll, ll> b){
	return a.f.f < b.f.f;
}

void solve(){
	vector<pair<pll, ll>> a(n);
	vll b(n);
	for(auto &it:b)it = -1;
	for(ll i = 0; i < n; i++)cin >> a[i].f.f >> a[i].f.s, a[i].s = i;
	sort(all(a), mc);
	cin >> m;
	for(ll i = 0; i < m; i++){
		ll x, y;
		cin >> x >> y;
		ll l = 0, r = n-1, midd = n-1;
		while(l <= r){
			ll mid = l + (r - l)/2;
			if(a[mid].f.f < x) l = mid + 1;
			else{
				midd = mid;
				r = mid - 1;
			}
		}
		if(a[midd].f.s*a[midd].f.s >= (a[midd].f.f - x)*(a[midd].f.f - x) + y*y){
			if(b[a[midd].s] == -1)b[a[midd].s] = i+1;
		}
		if(midd and a[midd-1].f.s*a[midd-1].f.s >= (a[midd-1].f.f - x)*(a[midd-1].f.f - x) + y*y){
			if(b[a[midd-1].s] == -1)b[a[midd-1].s] = i+1;
		}
	}
	ll ans = 0;
	for(auto it:b)if(it != -1)ans++;
	cout << ans << endl;
	for(auto it:b)cout << it << " ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}