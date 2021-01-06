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
	multiset<ll> s;
	for(ll i = 0; i < n; i++){
		ll d;
		cin >> d;
		s.insert(d);
	}
	vll a(30, 0), c(n, 0);
	for(auto it:s){
		for(ll i = 21; i >= 0; i--){
			ll b = 1ll<<i;
			if(b&it)a[i]++;
		}
	}
	for(ll i = 0; i < 30; i++) for(ll j = 1; j <= a[i]; j++)c[j-1] += 1ll<<i;
	ll ans = 0;
	for(auto it:c){
		ans += it*it;
		// cout << it << " ";
	}
	cout<<ans;
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