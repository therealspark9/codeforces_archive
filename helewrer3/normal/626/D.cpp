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
	vll a(n);
	for(auto &it:a)cin>>it;
	sort(all(a));
	vll b(2*a[n-1]+1,0), c(2*a[n-1]+1,0), d(2*a[n-1]+1,0), e, f;
	for(ll i = 0; i < n; i++) for(ll j = i+1; j < n; j++){
		if(c[a[j]-a[i]] == 0)f.pb(a[j]-a[i]);
		e.pb(a[j]-a[i]);
		d[a[j]-a[i]]++;
		c[a[j]-a[i]]=1;
	}
	for(ll i = 1; i < sz(c); i++){
		if(c[i] != 1)continue;
		for(auto it:f)b[i+it] += d[i]*d[it];
	};
	sort(all(e));
	ll ans = 0;
	for(ll i = 0; i < sz(b); i++){
		if(!b[i])continue;
		ll l = 0, r = sz(e)-1, midd = -1;
		while(l<=r){
			ll m = (l+r)/2;
			if(e[m]<=i)l=m+1;
			else r=m-1, midd = m;
		}
		if(midd == -1)continue;
		ans += b[i]*(sz(e)-midd);
	}
	double den = n*(n-1), num = ans;
	den /= 2;
	num /= den;
	num /= den;
	num /= den;
	cout<<num;
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