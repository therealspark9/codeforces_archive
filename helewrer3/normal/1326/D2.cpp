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
#define endl "\n"
using namespace std;

string pref(string s){
	string t = s, S = s;
	reverse(all(t));
	s = s + '#' + t;
	vll a(sz(s), 0);
	for(ll i = 1; i < sz(s); i++){
		ll j = a[i-1];
		while(j and s[i] != s[j])j = a[j-1];
		if(s[j] == s[i])j++;
		a[i] = j;
	}
	return S.substr(0, a[sz(s)-1]);
}


void solve(){
	string s;
	cin >> s;
	ll l = 0;
	while(l < sz(s)/2){
		if(s[l] != s[sz(s)-1-l])break;
		l++;
	}
	if(l) cout << s.substr(0,l);
	if(sz(s) > 2*l){
		string a = s.substr(l, sz(s) - 2*l);
		string ans1 = pref(a);
		reverse(all(a));
		string ans2 = pref(a);
		if(sz(ans1) < sz(ans2))swap(ans1, ans2);
		cout << ans1;
	}
	if(l) cout << s.substr(sz(s)-l, l);
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