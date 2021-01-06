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

ll n;

void input(){
	cin >> n;
}

void solve(){
	bool f = true;
	for(ll i = 2; i*i <= n; i++){
		if(n%i == 0) f = false;
	}
	bool g = true;
	for(ll i = 2; i*i <= (n-2); i++){
		if((n-2)%i == 0) g = false;
	}
	if(f)cout<<1;
	else if(g)cout<<2;
	else if(n%2)cout<<3;
	else cout<<2;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> T;
	while(T--){
		input();
		solve();
	}
	cin.get();
	return 0;
}