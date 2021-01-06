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

ll n, s;

void input(){
	cin >> n >> s;
	s*=8;
}

void solve(){
	vll a(n);
	mll mp;
	for(auto &it:a)cin >> it, mp[it]++;
	a.clear();
	for(auto it:mp)a.pb(it.f);
	ll l = 0, r = -1;
	while(r < sz(a)){
		r++;
		if(r==sz(a))break;
		ll siz = ceil(log2(r + 1))*n;
		if(siz <= s);
		else break;
	}
	if(r==sz(a))cout << 0;
	else{
		vll c(sz(a));
		c[0] = mp[a[0]];
		for(ll i = 1; i < sz(a); i++)c[i] = c[i-1] + mp[a[i]];
		ll ans = c.back() - c[r-1];
		while(r < sz(a)){
			l++;
			ll z = c[l-1] + c.back() - c[r];
			ans = min(ans, z);
			r++;
		}
		cout << ans;
	}
	
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