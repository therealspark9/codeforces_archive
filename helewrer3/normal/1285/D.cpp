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

vll p;

ll f(vll v, ll b){
	if(b<0)return 0;
	vll o, z;
	for(auto it:v){
		if(it&(1ll<<b))o.pb(it);
		else z.pb(it);
	}
	if(!sz(z))return f(o, b-1);
	if(!sz(o))return f(z, b-1);
	return min(f(o, b-1), f(z, b-1)) + p[b];
}


void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	p.pb(1);
	for(ll i = 1; i <= 60; i++)p.pb(p[sz(p)-1]*2);
	cout << f(a, 60);
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