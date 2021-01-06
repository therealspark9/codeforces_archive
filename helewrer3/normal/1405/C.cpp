//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n, k;

void input(){
	cin >> n >> k;
}

void solve(){
	string a;
	vll b(n), c(n);
	cin >> a;
	b[0] = (a[0] == '1');
	c[0] = (a[0] == '0');
	for(ll i = 1; i < n; i++)b[i] = (a[i] == '1') + b[i-1];
	for(ll i = 1; i < n; i++)c[i] = (a[i] == '0') + c[i-1];
	mll mp;
	for(ll i = k-1; i < n; i++){
		ll l = ((i-k >= 0)? b[i-k]:0);
		ll j = ((i-k >= 0)? c[i-k]:0);
		if(b[i] - l > k/2 or c[i] - j > k/2){cout<<"NO\n";return;}
		ll x = k/2 - (b[i] - l);
		ll y = k/2 - (c[i] - j);
		if(i == n-1)continue;
		if((a[i+1] == '1' and a[i-k+1] == '1') or (a[i+1] == '0' and a[i-k+1] == '0'))continue;
		if((a[i+1] == '0' and a[i-k+1] == '1') or (a[i+1] == '1' and a[i-k+1] == '0')){cout<<"NO\n";return;}
		if((a[i+1] == '0' and a[i-k+1] == '?' and !y) or (a[i+1] == '1' and a[i-k+1] == '?' and !x)){cout<<"NO\n";return;}
		if(a[i-k+1] == '?')a[i-k+1] = a[i+1];
		if(a[i+1] == '?') a[i+1] = a[i-k+1];
	}
	c[0] = (a[0] == '0');
	for(ll i = 1; i < n; i++)b[i] = (a[i] == '1') + b[i-1];
	for(ll i = 1; i < n; i++)c[i] = (a[i] == '0') + c[i-1];
	for(ll i = k-1; i < n; i++){
		ll l = ((i-k >= 0)? b[i-k]:0);
		ll j = ((i-k >= 0)? c[i-k]:0);
		if(b[i] - l > k/2 or c[i] - j > k/2){cout<<"NO\n";return;}
	}
	cout<<"YES\n";
		
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