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
	ll a, b, q;
	cin >> a >> b >> q;
	ll nax = a*b/(__gcd(a,b));
	vll c(nax+1,0);
	for(auto &it:c)it = 0;
	for(ll i = 1; i < nax+1; i++){
		c[i] += c[i-1];
		if((i%a)%b != (i%b)%a)c[i]++;
	}
	while(q--){
		ll l, r;
		cin >> l >> r;
		ll ans = 0;
		ans = (r/nax)*c[nax] + c[r%nax];
		l--;
		ans -= ((l/nax)*c[nax] + c[l%nax]);
		cout << ans << " ";
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