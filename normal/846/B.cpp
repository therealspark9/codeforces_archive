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

ll n, k, m;

void input(){
	cin >> n >> k >> m;
}

void solve(){
	vll a(k);
	for(auto &it:a)cin >>  it;
	ll su = 0;
	sort(all(a));
	for(auto it:a)su += it;
	ll ans = 0;
	for(ll i = 0; i <= n; i++){
		if(su*i > m) break;
		ll tm = m - su*i, t = k*i + i;
		for(ll j = 0; j < k-1; j++)
			for(ll p = 0; p < n-i; p++)
				if(tm >= a[j])tm-=a[j],t++;
		ans = max(ans, t);
	}
	cout<<ans;
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