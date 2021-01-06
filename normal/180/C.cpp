//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

string s;

void input(){
	cin >> s;
}

void solve(){
	pll a[sz(s)];
	a[0] = {(islower(s[0]) != 0), (isupper(s[0]) != 0)};
	for(ll i = 1; i < sz(s); i++)
		a[i] = {a[i-1].f + (islower(s[i]) != 0), a[i-1].s + (isupper(s[i]) != 0)};
	ll ans = sz(s) - a[sz(s)-1].f;
	for(ll i = 0; i < sz(s); i++){
		ll t = i+1 - a[i].s;
		t += sz(s) - 1 - i - (a[sz(s)-1].f - a[i].f);
		ans = min(ans, t);
	}
	cout << ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}