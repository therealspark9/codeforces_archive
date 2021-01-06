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

ll n, m;

void input(){
	cin >> n >> m;
}

void solve(){
	if(n <= 1){cout << 1;return;}
	ll l = 0, r = 10e9, midd = 0;
	while(l <= r){
		ll mid = l + (r-l)/2;
		ll x = mid*(mid+1)/2 + m;
		if(x < n)l = mid + 1;
		else midd = mid, r = mid - 1;
	}
	cout<< m + midd;
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
	}
	cout << endl;
	cin.get();
	return 0;
}