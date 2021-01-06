//May the force be with me
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


void solve(){
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin >> it;
	ll x = inf, y = 0;
	bool f = 0, g = 0;
	for(ll i = 0 ; i < n; i++){
		x = min(abs(a[i]), x);
		y += abs(a[i]);
		if(a[i]>=0)f=true;
		if(a[i]<0)g=true;
	}
	if(n == 1)cout<<a[0];
	else if(f and g)cout<<y;
	else cout<<y-x-x;
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