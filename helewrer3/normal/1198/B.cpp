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
#define umll unordered_map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n;
vll t(10e6, 0), p(10e6, 0);

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	ll q;
	cin >> q;
	for(ll i = 1; i <= q; i++){
		ll ty;
		cin >> ty;
		if(ty == 1){
			ll x,y;
			cin >> x >> y;
			x--;
			a[x] = y;
			t[x] = i;
		}
		else{
			ll x;
			cin >> x;
			p[i] = x;
		}
	}
	for(ll i = q+1; i >= 0; i--) p[i] = max(p[i], p[i+1]);
	for(ll i = 0; i < n; i++)a[i] = max(a[i], p[t[i]]);
	for(auto it:a)cout << it <<" ";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> t;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}