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
	cin >> s;
	ll n = sz(s);
	ll dx = 0, dy = 0, pdx, pdy;
	for(ll i = 0; i < n; i++){
		pdx = dx, pdy = dy;
		if(s[i] == 'R')dx++;
		if(s[i] == 'L')dx--;
		if(s[i] == 'U')dy++;
		if(s[i] == 'D')dy--;
		char ch = s[i];
		ll x = 0, y = 0;
		for(ll j = 0; j < n; j++){
			pdx = x, pdy = y;
			if(s[j] == 'R')x++;
			if(s[j] == 'L')x--;
			if(s[j] == 'U')y++;
			if(s[j] == 'D')y--;
			if(x == dx and y == dy)x = pdx, y = pdy;
		}
		if(x == 0 and y == 0){
			cout << dx << " " << dy;
			return;
		}
	}
	cout<<"0 0";
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