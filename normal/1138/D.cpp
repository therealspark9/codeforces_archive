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
	string a, b;
	cin >> a >> b;
	ll x = 0, y = 0, xx = 0, yy = 0;
	for(auto it:a){
		if(it == '1')x++;
		else y++;
	}
	for(auto it:b){
		if(it == '1')xx++;
		else yy++;
	}
	ll idx = -1, t = 0;
	for(ll i = 1; i < sz(b); i++){
		if(b[i] == b[t]){
			t++;
			if(idx == -1) idx = i;
		}
		else{
			t = 0;
			idx = -1;
			if(b[i] == b[t]){
				t++;
				if(idx == -1) idx = i;
			}
		}
	}
	ll nxx = 0, nyy = 0;
	for(ll i = idx; i < sz(b); i++){
		if(b[i] == '1')nxx++;
		else nyy++;
	}
	nxx = xx - nxx;
	nyy = yy - nyy;
	if(sz(b) > sz(a) or (xx and x/xx == 0) or (yy and y/yy == 0))cout<<a;
	else if(xx and yy and idx != -1){
		cout << b;
		x -= xx;
		y -= yy;
		ll cnt = min(x/nxx, y/nyy);
		string T = "";
		for(ll i = t; i < sz(b); i++)T += b[i];
		for(ll i = 0; i < cnt; i++)cout<<T;
		x -= cnt*nxx;
		y -= cnt*nyy;
		for(ll i = 0; i < x; i++)cout<<1;
		for(ll i = 0; i < y; i++)cout<<0;
	}
	else if(xx and yy){
		ll cnt = min(x/xx, y/yy);
		for(ll i = 0; i < cnt; i++)cout<<b;
		x -= cnt*xx;
		y -= cnt*yy;
		for(ll i = 0; i < x; i++)cout<<1;
		for(ll i = 0; i < y; i++)cout<<0;
	}
	else if(xx){
		sort(rall(a));
		cout << a;
	}
	else{
		sort(all(a));
		cout << a;
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi