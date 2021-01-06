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
	ll n;
	cin >> n;
	vll a(n);
	for(auto &it:a)cin>>it;
	//maximum
	vll b = a;
	sort(all(b));
	ll t = inf;
	set<ll> s;
	for(ll i = n-1; i >= 0; i--){
		if(b[i] < t) b[i]++;
		else if(b[i] > t)b[i]--;
		t = b[i]-1;
		s.insert(b[i]);
	}
	//minimum
	mll mp;
	sort(all(a));
	for(auto it:a)mp[it]=1;
	ll ans = 0;
	ll st = a[0];
	while(st < 2*n){
		ll x = 1;
		if(mp.count(st))ans++, x = 3;
		st += x;
	}
	
	cout << ans << " " << sz(s);
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