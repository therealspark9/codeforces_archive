#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long)(x).size())
#define mll map<long long, long long>
#define pll pair<long long, long long>
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	vector<long double> a(n),b(n);
	for(auto &it:a)cin>>it;
	for(auto &it:b)cin>>it;
	map<long double, ll>mp;
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		if(!a[i]){
			ans+=b[i]==0;
			continue;
		}	
		long double d = b[i]/a[i];
		mp[d]++;
	}
	ll t = 0;
	for(auto it:mp)t=max(t,it.s);
	cout<<ans+t;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	cout.precision(20);
	ll t;
	t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
	}
	cout << endl;
	return 0;
}