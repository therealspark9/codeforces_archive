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
	vll a(2*n);
	for(auto &it:a)cin>>it;
	vll v;
	ll bl = 0, mx = 0;
	for(auto it:a){
		if(it > mx){
			if(bl)v.pb(bl);
			bl=0, mx=it;
		}
		bl++;
	}
	if(bl)v.pb(bl);
	ll dp[n+1];
	for(auto &it:dp)it=0;
	dp[0] = 1;
	for(auto it:v) for(ll i = n-it; i >= 0; i--) if(dp[i])dp[i+it]=1;
	if(dp[n])cout<<"YES";
	else cout<<"NO";
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