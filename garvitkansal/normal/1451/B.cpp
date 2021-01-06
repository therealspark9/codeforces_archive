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
	ll n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	while(q--){
		ll l, r;
		cin >> l >> r;
		l--, r--;
		string t = "";
		for(ll i = l; i <= r; i++)t += s[i];
		ll x = 0, f = 0, h = 0, nl = inf, nr = -inf;
		for(ll i = 0; i < n; i++){
			if(x >= sz(t)){
				ll g = 0;
				f = 1;
				if(nr-nl+1 == sz(t)){
					for(ll j = i; j < n; j++)if(s[j] == t[sz(t)-1])g = 1;
					f = g;
				}
				h = 1;
				break;
			}
			if(s[i] == t[x])x++, nl = min(nl, i), nr = max(nr, i);
		}
		if(x >= sz(t) and !h){
			f = 1;
			if(nr-nl+1 == sz(t)) f = 0;
		}
		if(f)cout<<"YES";
		else cout<<"NO";
		cout << endl;
	}
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