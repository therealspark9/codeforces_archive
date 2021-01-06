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

ll n, m;
vll a, b;

void input(){
	cin >> n >> m;
}

bool check(ll x){
	bool f = true;
	for(auto it:a){
		f = false;
		for(auto jt:b){
			f |= ((x|(it&jt))==x);
		}
		if(!f)return false;
	}
	return true;
}

void solve(){
	a.resize(n), b.resize(m);
	ll ans = inf;	
	for(auto &it:a)cin >>  it;
	for(auto &it:b)cin >>  it;
	for(ll i = 0; i <= 600; i++){
		if(check(i)){ans = i; break;}
	}
	cout << ans;		
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cin.get();
	return 0;
}