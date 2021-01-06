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

ll const nax = 2 * 10e5 + 5;

void solve(){
	ll n, k;
	cin >> n >> k;
	vll a(n), cnt(nax, 0);
	for(ll i = 0; i < n; i++)cin >> a[i];
	ll d = 0, mn = inf;
	for(ll i = 0; i < n; i++){
		d = max(a[i], d);
		mn = min(a[i], mn);
		cnt[a[i]]++;
	}
	ll h = nax, c = 0, ans = 0, su = 0;
	while(1){
		ll x = su - (h-1)*c;
		if(x > k){
			ans++;
			d = h;
			su = h*c;
		}
		h--;
		if(h == mn) break;
		c += cnt[h];
		su += cnt[h]*h;
	}
	if(d != mn)ans++;
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