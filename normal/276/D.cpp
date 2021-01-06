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
	ll l, r;
	cin >> l >> r;
	vll a, b;
	while(r){
		a.pb(r&1);
		r>>=1;
	}
	b.resize(sz(a), 0);
	ll ans = 0, num = 0;
	reverse(all(a));
	for(ll i = 0; i < sz(a); i++){
		if(a[i] == 0){
			num += 1ll<<(sz(a)-1-i);
			if(num >= l) b[i] = 1;
			else break;
		}
		if(a[i] == 1){
			if(l >= (1ll<<(sz(a)-1-i)))b[i] = 1;
		}
	}
	for(ll i = 0; i < sz(a); i++) {
		if (a[i] and b[i]) continue;
		else if(a[i] or b[i])ans+=(1ll<<(sz(a)-1-i));
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