//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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
using namespace std;

ll n;

void input(){
	cin >> n;
}

void solve(){
	ll a[n+1][n+1];
	vll b, c;
	for(ll i = 1; i <= n*n; i+=2)b.pb(i);
	for(ll i = 2; i <= n*n; i+=2)c.pb(i);
	for(ll i = 0; i <= n; i++) for(ll j = 0; j <= n; j++)a[i][j] = -1;
	for(ll i = 1; i <= n; i++){
		a[n/2+1][i] = b.back();
		b.pop_back();
	}
	ll r = n-1, l = 2;
	for(ll i = n/2+2; i <= n; i++){
		for(ll j = l; j <= r; j++){
			a[i][j] = b.back();
			b.pop_back();
		}
		l++, r--;
	}
	r = n-1, l = 2;
	for(ll i = n/2; i >= 1; i--){
		for(ll j = l; j <= r; j++){
			a[i][j] = b.back();
			b.pop_back();
		}
		l++, r--;
	}
	for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++){
		if(a[i][j] != -1)continue;
		a[i][j] = c.back();
		c.pop_back();
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++)cout << a[i][j] << " ";
		cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}