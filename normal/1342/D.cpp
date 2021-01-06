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
	ll n, k;
	cin >> n >> k;
	vll a(n), b(k+1);
	for(auto &it:a)cin>>it;
	for(ll i = 1; i <= k; i++)cin>>b[i];
	sort(all(a));
	vll v, tv;
	ll sz = 1, tsz = 1, ans = 0;
	for(ll i = 0; i < n; i++){
		tsz = min(b[a[i]], tsz-1);
		if(tsz <= 0){
			if(sz(tv)){
				ans++;
				tv.clear();
			}
			tsz = b[a[i]];
		}
		tv.pb(a[i]);
	}
	if(sz(tv))ans++;
	cout<<ans<<endl;
	for(ll i = 0; i < n; i++){
		sz = min(b[a[i]], sz-1);
		if(sz <= 0){
			if(sz(v)){
				cout << sz(v) << " ";
				for(auto it:v)cout<< it << " ";
				cout<<endl;
				v.clear();
			}
			sz = b[a[i]];
		}
		v.pb(a[i]);
	}
	cout<<sz(v)<<" ";
	for(auto it:v)cout<<it<<" ";
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