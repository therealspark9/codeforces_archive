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

ll n;

void input(){
	cin >> n;
}

void solve(){
	vector<pll> a(n);
	for(auto &it:a)cin >>  it.f >> it.s;
	sort(all(a));
	ll ans = inf;
	vll dp(n, 0);
	for(ll i = 1; i < n; i++){
		ll st = 0, ed = i-1, midd = i;
		ll key = a[i].f - a[i].s;
		while(st <= ed){
			ll mid = st + (ed-st)/2;
			if(a[mid].f < key) st = mid+1;
			else midd = mid, ed = mid-1;
		}
		dp[i] = i - midd;
		if(midd != 0)dp[i] += dp[midd-1];
	}
	for(ll i = 0; i < n; i++)ans = min(ans, dp[i] + n-1-i);
	cout << ans;
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