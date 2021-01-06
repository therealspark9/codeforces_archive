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
	vll a(n), b(n);
	mll c, d;
	for(auto &it:a)cin>>it;
	for(auto &it:b)cin>>it;
	reverse(all(a));
	c[0] = d[0] = n;
	vll sa(n,0), sb(n,0);
	for(ll i = n-1; i >= 0; i--){
		if(b[i] == 1)sb[i]++;
		else sb[i]--;
		if(i != n-1)sb[i] += sb[i+1];
		if(!d.count(sb[i])) d[sb[i]] = i;
		else d[sb[i]] = min(d[sb[i]], i);
	}
	for(ll i = n-1; i >= 0; i--){
		if(a[i] == 2)sa[i]++;
		else sa[i]--;
		if(i != n-1)sa[i] += sa[i+1];
		if(!c.count(sa[i])) c[sa[i]] = i;
		else c[sa[i]] = min(c[sa[i]], i);
	}
	ll ans = inf;
	for(ll i = 0; i < n; i++){
		if(!c.count(sb[i]))continue;
		ans = min(ans, c[sb[i]] + i);
	}
	ans = min(ans, c[0] + n);
	cout << ans;
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