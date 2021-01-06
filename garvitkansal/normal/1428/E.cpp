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
using namespace std;

ll sq(ll x){return x*x;}

ll f(ll l, ll p){
	ll w = l/p;
	ll p2 = l%p;
	ll p1 = p - p2;
	return p1*sq(w) + p2*sq(w+1);
}

void solve(){
	ll n, k;
	cin >> n >> k;
	vll a(n);
	for(auto &it:a)cin >> it;
	priority_queue<pair<ll, pll>> s;
	ll ans = 0, d = k-n;
	for(auto it:a){
		s.push({f(it,1) - f(it,2), {it,2}});
		ans += sq(it);
	}
	while(d){
		pair<ll, pll> v = s.top();
		s.pop();
		ans -= v.f;
		s.push({f(v.s.f, v.s.s)-f(v.s.f, v.s.s+1), {v.s.f, v.s.s+1}});
		d--;
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