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
using namespace std;


void solve(){
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll cnt = 0;
	while(sz(s) and s[0] == s.back()){
		s.pop_back();
		cnt++;
	}
	if(!sz(s)){
		if(cnt >= 3) cout << (cnt + 2) / 3;
		else cout << 0;
		return;
	}
	s += "%";
	ll ans = 0;
	for(ll i = 0; i < sz(s); i++){
		cnt++;
		if(s[i] != s[i+1]){
			ans += cnt/3;
			cnt = 0;
		}
	}
	cout << ans + cnt/3;
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