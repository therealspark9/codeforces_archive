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

void input(){
	cin >> n;
}

void solve(){
	vector<pll> a(n);
	for(auto &it:a)cin >> it.f >> it.s;
	set<ll> mp;
	for(ll i = 2; i*i <= a[0].f; i++){
		if(a[0].f%i==0){
			mp.insert(i);
			while(a[0].f%i==0)a[0].f/=i;
		}
	}
	if(a[0].f > 1)mp.insert(a[0].f);
	
	for(ll i = 2; i*i <= a[0].s; i++){
		if(a[0].s%i==0){
			mp.insert(i);
			while(a[0].s%i==0)a[0].s/=i;
		}
	}
	if(a[0].s > 1)mp.insert(a[0].s);
	
	for(auto it:mp){
		bool f = true;
		for(ll i = 1; i < n; i++){
			if(a[i].f%it != 0 and a[i].s%it != 0){
				f = false;
				break;
			}
		}
		if(f){cout<<it;return;}
	}
	cout<<-1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}