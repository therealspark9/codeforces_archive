//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll x1, y_1, x2, y2, x3, y3;

void input(){
	cin >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3;
}

void solve(){
	ll a[3] = {x1, x2, x3};
	ll b[3] = {y_1, y2, y3};
	sort(a, a+3);
	sort(b, b+3);
	ll x = a[1], y = b[1];
	set<pll> s;
	ll tx = x, ty = y;
	while(tx != x1){
		s.insert({tx, ty});
		if(tx > x1)tx--;
		else tx++;
	}
	while(ty != y_1){
		s.insert({tx, ty});
		if(ty > y_1)ty--;
		else ty++;
	}
	tx = x, ty = y;
	while(tx != x2){
		s.insert({tx, ty});
		if(tx > x2)tx--;
		else tx++;
	}
	while(ty != y2){
		s.insert({tx, ty});
		if(ty > y2)ty--;
		else ty++;
	}
	tx = x, ty = y;
	while(tx != x3){
		s.insert({tx, ty});
		if(tx > x3)tx--;
		else tx++;
	}
	while(ty != y3){
		s.insert({tx, ty});
		if(ty > y3)ty--;
		else ty++;
	}
	s.insert({x1, y_1});
	s.insert({x2, y2});
	s.insert({x3, y3});
	cout << sz(s) << endl;
	for(auto it:s)cout << it.f << " " << it.s << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}