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
	vll a(n), b(n+1), ans(n, 0);
	set<ll> s, idx;
	for(ll i = 0; i < n; i++)cin >> a[i];
	for(ll i = 0; i < n; i++)b[a[i]] = i, idx.insert(i), s.insert(a[i]);
	ll f = 0;
	while(!idx.empty()){
		ll m = b[(*s.rbegin())];
		vll c;
		ll cnt = 0;
		auto it = idx.find(m);
		while(cnt != k+1){
			if(it == idx.end())break;
			c.pb((*it));
			it++, cnt++;
		}
		cnt = 0;
		it = idx.find(m);
		if(it != idx.begin()){
			it--;
			while(cnt != k){
				if(it == idx.end())break;
				if(it == idx.begin()){
					c.pb((*it));
					break;
				}
				c.pb((*it));
				it--, cnt++;
			}
		}
		for(auto jt:c){
			// cout << jt << " ";
			ans[jt] = 1 + f;
			idx.erase(jt);
			s.erase(a[jt]);
		}
			// cout << endl;
		f = 1 - f;
	}
	for(auto it:ans)cout<<it;
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