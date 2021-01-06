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
	priority_queue<ll> a;
	for(ll i = 1; i <= n; i++)a.push(i);
	cout << 2 << endl;
	while(a.size() != 1){
		ll u, v;
		u = a.top();
		a.pop();
		v = a.top();
		a.pop();
		ll d = (u+v+1)/2;
		a.push(d);
		cout << u << " " << v << endl;
	}
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