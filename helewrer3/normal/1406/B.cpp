//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(rall(a));
	ll ans = a[0];
	vll b;
	bool f = 1;
	for(ll i = 1; i < n; i++){
		if(a[i] != 0)b.pb(a[i]);
		else f = false;
	}
	if(sz(b) < 4) cout << 0 << endl;
	else{
		ll x = 1, y = 1, p = 1, q = 1;
		for(ll i = 0; i < 4; i++)x*=b[i];
		for(ll i = 0; i < 2; i++)p*=b[i];
		for(ll i = sz(b) - 1; i >= sz(b) - 4; i--)y*=b[i];
		for(ll i = sz(b) - 1; i >= sz(b) - 2; i--)q*=b[i];
		
		ans = max({ans*x, ans*y, ans*p*q});
		if(!f) ans = max(ans, 0ll); 
		cout << ans << endl;
	}
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