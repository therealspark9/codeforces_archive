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
	vll a(6);
	for(auto &it:a)cin >> it;
	ll n;
	cin >> n;
	vll b(n), fre(n);
	sort(all(a));
	set<pll> c;
	for(auto &it:b)cin >> it;
	for(ll i = 0; i < n; i++){
		fre[i] = 5;
		c.insert({b[i] - a[fre[i]], i});
	}
	ll ans = (*c.rbegin()).f - (*c.begin()).f;
	while(sz(c)){
		pll p = (*c.begin());
		c.erase(c.begin());
		fre[p.s]--;
		if(fre[p.s] < 0) break;
		c.insert({b[p.s] - a[fre[p.s]], p.s});
		ans = min(ans, (*c.rbegin()).f - (*c.begin()).f);
	}
	cout<<ans;
}

//Thanks JENXLS for the idea

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