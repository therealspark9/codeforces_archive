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


void solve(){
	ll n;
	cin >> n;
	vll a(n+1,0), b(n+1);
	for(ll i = 1; i <= n; i++)cin >> a[i];
	b[0] = 0;
	for(ll i = 1; i <= n; i++)b[i] = b[i-1] + a[i];
	set<ll> s;
	s.insert(0);
	ll l = 0, r = 1, ans = 0;
	while(l <= n){
		while(r <= n and !s.count(b[r])){
			s.insert(b[r]);
			r++;
		}
		ans += r-l;
		ans--;
		s.erase(b[l]);
		l++;
	}
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