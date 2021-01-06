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
mll mp;

void input(){
	cin >> n;
}

void solve(){
	string a;
	cin >> a;
	mp.clear();
	ll ans = 0, s = 0;
	mp[0]=1;
	for(ll i = 0; i < n; i++){
		s += (a[i] - '1');
		ans += mp[s];
		mp[s]++;
	}
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}