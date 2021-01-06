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

bool mc(pair<pll, ll> p1, pair<pll, ll> p2){
	return p1.f.f > p2.f.f;
}
bool mcr(pair<pll, ll> p1, pair<pll, ll> p2){
	return p1.f.f < p2.f.f;
}

void solve(){
	ll n;
	cin >> n;
	vector<pair<pll, ll>> a(n);
	for(ll i = 0; i < n; i++)cin >> a[i].f.f >> a[i].f.s, a[i].s = i;
	ll o = 0, z = 0;
	for(ll i = 0; i < n; i++){
		if(a[i].f.f < a[i].f.s)o++;
		else if(a[i].f.f > a[i].f.s)z++;
	}
	if(o >= z){
		cout << o << endl;
		sort(all(a), mc);
		for(ll i = 0; i < n; i++){
			if(a[i].f.f < a[i].f.s)cout << a[i].s+1 << " ";
		}
	}
	else{
		cout << z << endl;
		sort(all(a), mcr);
		for(ll i = 0; i < n; i++){
			if(a[i].f.f > a[i].f.s)cout << a[i].s+1 << " ";
		}
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