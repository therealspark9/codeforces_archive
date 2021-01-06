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

ll n;

void input(){
	cin >> n;
}

void solve(){
	string s;
	cin >> s;
	ll t = 0;
	vector<pll> a;
	for(ll i = 0; i < n; i++){
		if(s[i] == 'G')t++;
		if(s[i] == 'S' and t){
			a.pb({i-1, t});
			t = 0;
		}
	}
	if(t)a.pb({n-1, t});
	ll ans = 0;
	sort(all(a));
	for(ll i = 0; i < sz(a); i++) {
		ans = max(ans, a[i].s);
		if(sz(a) >= 2)ans = max(ans, a[i].s+1);
	}
	for(ll i = 0; i < sz(a)-1; i++){
		bool f = false;
		if(sz(a) >= 3)f = true;
		if(abs(a[i].f - (a[i+1].f - a[i+1].s)) == 1)ans = max(ans, a[i].s + a[i+1].s + f);
	}
	cout<<ans;
		
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}