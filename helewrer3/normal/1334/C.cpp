//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n;

void input(){
	cin >> n;
}

void solve(){
	vector<pll> a(n);
	for(auto &it:a)cin >> it.f >> it.s;
	ll ans = a[0].f;
	for(ll i = 1; i < n; i++) ans += max(0ll, a[i].f-a[i-1].s);
	ll tans = ans;
	for(ll i = 1; i < n; i++){
		tans -= max(0ll, a[i].f - a[i-1].s);
		tans -= a[i-1].f;
		tans += a[i].f;
		tans += max(0ll, a[i-1].f - a[(i-2+n)%n].s);
		ans = min(ans, tans);
	}
	cout<<ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}