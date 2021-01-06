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
	cin  >> n >> k;
	char a[4][n];
	for(ll i = 0;i < 4; i++) for(ll j = 0; j < n; j++)a[i][j] = '.';
	ll l = 1, r = n-2;
	while(l < n/2 and r > n/2){
		if(k <= 1) break;
		a[1][l] = a[1][r] = '#';
		k -= 2;
		l++, r--;
	}
	if(k){
		a[1][n/2] = '#';
		k--;
	}
	l = 1, r = n-2;
	while(l < n/2 and r > n/2){
		if(k <= 1) break;
		a[2][l] = a[2][r] = '#';
		k -= 2;
		l++, r--;
	}
	if(k)a[2][n/2] = '#';
	cout << "YES" << endl;
	for(ll i = 0;i < 4; i++) {
		for(ll j = 0; j < n; j++)cout << a[i][j];
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
		solve();
		cout << endl;
	}
	cin.get();
	return 0;
}
//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi