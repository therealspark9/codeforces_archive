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

bool check(ll x, vll a, vll b, ll n){
	for(ll i = 0; i < x; i++) if(min(a[i], b[n - (x - i)]) != a[i]) return false;
	for(ll i = x; i < n; i++) if(max(a[i], b[i-x]) != a[i])return false;
	return true;
}


void solve(){
	ll n;
	cin >> n;
	vll a(n), b, vis(2*n+1, 0);
	for(auto &it:a)cin >> it, vis[it]++;
	for(ll i = 1; i <= 2*n; i++)if(!vis[i])b.pb(i);
	sort(all(a));
	sort(all(b));
	ll mn = 0, mx = n;
	ll l = 0, r = n;
	while(l <= r){
		ll mid = (l+r)/2;
		if(check(mid, a, b, n))mn = mid, r = mid-1;
		else l = mid+1;
	}
	l = mn, r = n;
	mx = mn;
	while(l <= r){
		ll mid = (l+r)/2;
		if(check(mid, a, b, n))mx = mid, l = mid+1;
		else r = mid-1;
	}
	cout << mx-mn+1;
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
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi