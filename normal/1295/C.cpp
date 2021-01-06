//May the force be with me
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


void solve(){
	string s, t;
	cin >> s >> t;
	ll ans = 1;
	vll a[26];
	for(ll i = 0; i < sz(s); i++){
		a[s[i] - 'a'].pb(i);
	}
	ll pos = -1;
	for(ll i = 0; i < sz(t); i++){
		if(!sz(a[t[i] - 'a'])){
			cout << -1;
			return;
		}
		auto it = upper_bound(all(a[t[i] - 'a']), pos);
		if(it == a[t[i] - 'a'].end()){
			ans++;
			pos = a[t[i] - 'a'][0];
		}
		else pos = (*it);
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