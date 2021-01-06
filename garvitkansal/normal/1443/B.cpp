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


void solve(){
	string s;
	ll a, b;
	cin >> a >> b;
	cin >> s;
	vll c;
	ll su = 0;
	for(auto it:s){
		if(it == '1')su++;
		else{
			if(su)c.pb(su);
			su = 0;
		}
	}
	if(su)c.pb(su);
	su = 0;
	for(auto it:c)su += it;
	su = sz(s) - su;
	for(auto it:s){
		if(it == '0')su--;
		else break;
	}
	reverse(all(s));
	for(auto it:s){
		if(it == '0')su--;
		else break;
	}
	cout << min(sz(c)*a, a + su*b);
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