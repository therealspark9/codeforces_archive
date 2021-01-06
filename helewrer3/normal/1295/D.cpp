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
	ll a, m;
	cin >> a >> m;
	ll g = __gcd(a, m);
	a/=g, m/=g;
	ll tm = m;
	vll v;
	if(m%2 == 0)v.pb(2);
	while(m%2 == 0)m/=2;
	for(ll i = 3; i*i <= m; i+=2){
		if(m%i == 0) v.pb(i);
		while(m%i == 0)m/=i;
	}
	if(m!=1)v.pb(m);
	ll ans = tm;
	for(auto it:v)ans = ans - ans/it;
	cout<<ans;
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