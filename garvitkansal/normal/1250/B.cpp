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
	ll n, k;
	cin >> n >> k;
	vll a(n), b(k+1, 0), c;
	for(auto &it:a)cin>>it;
	for(auto it:a)b[it]++;
	for(auto it:b)if(it)c.pb(it);
	sort(all(c));
	priority_queue<ll> takenout;
	priority_queue<pair<ll, pll>> pairs;
	if(sz(c)%2){
		takenout.push(c[sz(c)-1]);
		c.pop_back();
	}
	for(ll i = 0; i < sz(c)/2; i++)pairs.push({c[i]+c[sz(c)-1-i], {i, sz(c)-1-i}});
	ll ans = inf;
	while(!pairs.empty()){
		ll cap = pairs.top().f;
		if(sz(takenout))cap = max(cap, takenout.top());
		ans = min(ans, (sz(takenout)+sz(pairs))*cap);
		pair<ll, pll> p = pairs.top();
		pairs.pop();
		takenout.push(c[p.s.f]);
		takenout.push(c[p.s.s]);
	}
	ans = min(ans, sz(takenout)*takenout.top());
	cout << ans;
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